#pragma once
#include <iostream>

namespace study_list
{
    template <class T>
    struct __list_node
    {
        __list_node<T>* prev; // 修改为prev
        __list_node<T>* next; // 修改为next
        T _data;
    };

    template <class T>
    class list
    {
        typedef __list_node<T> Node;

    public:
        struct __list_iterator // 迭代器结构
        {
            Node* _node;

            __list_iterator(Node* node) : _node(node)
            {
            }

            T& operator*()
            {
                return _node->_data;
            }
            T* operator->()
            {
                return &(_node->_data);
            }
            __list_iterator& operator++()
            {
                _node = _node->next; // 修改为next
                return *this;
            }

            __list_iterator operator++(int)//int参数的存在是为了区分前置和后置++
            {
                __list_iterator tmp = *this;
                _node = _node->next; // 修改为next
                return *this;
            }

            __list_iterator& operator--()
            {
                _node = _node->prev; // 修改为next
                return *this;
            }

            bool operator!=(const __list_iterator& it) const
            {
                return _node != it._node;
            }
        };

        typedef __list_iterator iterator; // 移除<T>

        // 带头双向循环链表
        list()
        {
            _head = new Node();
            _head->next = _head; // 修改为next
            _head->prev = _head; // 修改为prev
        }

        ~list()
        {
            clear();
            delete _head;
        }

        void push_back(const T& data)
        {
            Node* tail = _head->prev; // 修改为prev
            Node* new_node = new Node();
            new_node->_data = data ;
            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = _head;
            _head->prev = new_node;
        }

        iterator begin() { return iterator(_head->next); } // 修改为next
        iterator end() { return iterator(_head); }

        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                erase(it++);
            }
        }

        void erase(iterator& it)
        {
            delete[] it._node;
        }
    private:
        Node* _head;
    };

    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        lt.push_back(6);

        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            std::cout << *it << " ";
            ++it;
        } //lt.end() = head
        std::cout << std::endl;
    }
    struct Data
    {
        int _year = 0;
        int _month = 1;
        int _day = 1;
    };
    void test_list2()
    {
        list<Data> lt;
        lt.push_back(Data());
        lt.push_back(Data());
    }
}

//把迭代器弄成自定义类型
//然后符号重载 实现迭代器操作


//思考const_iterator<T,T &,T*>  template<classT,class Ref,class Ptr>