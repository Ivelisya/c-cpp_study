#pragma once
#include <vector>
#include <functional>
using namespace std;

namespace CLOSED_HASH
{
    enum State
    {
        EMPTY,
        EXIST,
        DELETE
    };

    template <class T>
    struct HashData
    {
        T _data;
        State _state;

        HashData() : _state(EMPTY) {}
    };

    template <class K, class T, class KeyOfT>
    class HashTable
    {
    public:
        HashTable(size_t initialSize = 8) : _tables(initialSize), _num(0) {}

        bool Insert(const T &d)
        {
            KeyOfT kt;
            // Calculate the index for the key
            size_t index = std::hash<K>()(kt(d)) % _tables.size();

            // If the load factor is too high, rehash
            if (_num > 0.7 * _tables.size())
            {
                Rehash();
                index = std::hash<K>()(kt(d)) % _tables.size(); // Recalculate index
            }

            while (_tables[index]._state == EXIST)
            {
                if (kt(_tables[index]._data) == kt(d))
                {
                    return false; // Already exists
                }
                ++index;
                if (index == _tables.size())
                {
                    index = 0; // Wrap around
                }
            }

            _tables[index]._data = d;
            _tables[index]._state = EXIST;
            _num++;
            return true;
        }

        HashData<T> *Find(const K &key)
        {
            KeyOfT kt;
            size_t index = std::hash<K>()(key) % _tables.size();

            while (_tables[index]._state != EMPTY)
            {
                if (_tables[index]._state == EXIST && kt(_tables[index]._data) == key)
                {
                    return &_tables[index]; // Found and valid
                }
                ++index;
                if (index == _tables.size())
                {
                    index = 0; // Wrap around
                }
            }
            return nullptr; // Not found
        }

        bool Erase(const K &key)
        {
            HashData<T> *ret = Find(key);
            if (ret)
            {
                ret->_state = DELETE;
                _num--;
                return true;
            }
            return false;
        }

    private:
        std::vector<HashData<T>> _tables;
        size_t _num = 0; // Number of valid entries

        void Rehash()
        {
            std::vector<HashData<T>> oldTables = _tables;
            _tables.resize(oldTables.size() * 2); // Expand table
            for (auto &entry : _tables)
            {
                entry._state = EMPTY; // Clear new hash table
            }
            _num = 0; // Reset count

            for (const auto &oldEntry : oldTables)
            {
                if (oldEntry._state == EXIST)
                {
                    Insert(oldEntry._data); // Reinsert
                }
            }
        }
    };

    template <class K>
    struct SetKeyOfT
    {
        const K &operator()(const K &key) const
        {
            return key;
        }
    };
}

namespace OPEN_HASH
{
    template <class T>
    struct HashNode
    {
        T _data;
        HashNode *_next;
    };

    template <class K, class T, class KeyOfT>
    class HashTable
    {
        typedef HashNode<T> *Node;

    public:
        HashTable(size_t initialSize = 8) : _tables(initialSize, nullptr), _num(0) {}

        bool Insert(const T &data)
        {
            KeyOfT koft;

            // If load factor is 1 (resize the table)
            if (_tables.size() == _num)
            {
                vector<Node> newTables(_tables.size() * 2, nullptr); // resize and initialize with nullptr
                size_t newSize = newTables.size();

                // Rehash all the current nodes into the new table
                for (size_t i = 0; i < _tables.size(); ++i)
                {
                    Node cur = _tables[i];
                    while (cur)
                    {
                        Node next = cur->_next;
                        size_t index = std::hash<K>()(koft(cur->_data)) % newSize;

                        // Insert the current node at the head of the corresponding bucket in the new table
                        cur->_next = newTables[index];
                        newTables[index] = cur;

                        cur = next;
                    }
                }

                // Swap the old table with the new one
                _tables.swap(newTables);
            }

            // Calculate the index for the data
            size_t index = std::hash<K>()(koft(data)) % _tables.size();
            Node cur = _tables[index];

            // Traverse the linked list to check for duplicates
            while (cur)
            {
                if (koft(cur->_data) == koft(data))
                {
                    return false; // Already exists
                }
                cur = cur->_next;
            }

            // Insert the new data at the head of the list
            Node newNode = new HashNode<T>;
            newNode->_data = data;
            newNode->_next = _tables[index];
            _tables[index] = newNode;

            ++_num;
            return true;
        }

        HashNode<T> *Find(const K &key)
        {
            KeyOfT koft;
            size_t index = std::hash<K>()(key) % _tables.size();
            Node cur = _tables[index];

            while (cur)
            {
                if (koft(cur->_data) == key)
                {
                    return cur; // Found
                }
                cur = cur->_next;
            }
            return nullptr; // Not found
        }

        bool Erase(const K &key)
        {
            size_t index = std::hash<K>()(key) % _tables.size();
            Node cur = _tables[index];
            Node prev = nullptr;

            while (cur)
            {
                if (_getKey(cur->_data) == key)
                {
                    if (prev)
                    {
                        prev->_next = cur->_next;
                    }
                    else
                    {
                        _tables[index] = cur->_next;
                    }
                    delete cur;
                    --_num;
                    return true;
                }
                prev = cur;
                cur = cur->_next;
            }
            return false;
        }

    private:
        vector<Node> _tables;
        size_t _num = 0; // 已存储的数据数量
        KeyOfT _getKey;  // 键提取器函数对象
    };
    
}


//仿函数 -> 可以像函数一样调用的类