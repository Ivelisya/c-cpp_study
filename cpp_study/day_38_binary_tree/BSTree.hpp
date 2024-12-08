#include <iostream>
#include <pstl/execution_defs.h>
using namespace std;

template <class K>
struct BTreeNode
{
    BTreeNode<K>* _left;
    BTreeNode<K>* _right;
    K _key;

    BTreeNode(const K& key) : _left(nullptr), _right(nullptr), _key(key)
    {
    }
};

template <class K>
class BTree
{
    typedef BTreeNode<K> Node;

public:
    BTree() : _root(nullptr)
    {
    }

    bool Insert(const K& key)
    {
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;

        while (cur)
        {
            parent = cur; // 每次循环更新父节点
            if (cur->_key > key)
            {
                cur = cur->_left;
            }
            else if (cur->_key < key)
            {
                cur = cur->_right;
            }
            else
            {
                return false; // 键值已存在
            }
        }

        // 创建新节点并连接到父节点
        Node* newNode = new Node(key);
        if (parent->_key > key)
        {
            parent->_left = newNode;
        }
        else
        {
            parent->_right = newNode;
        }
        return true; // 成功插入
    }

    void _InOrder(Node* root)
    {
        if (root == nullptr)
            return;
        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }

    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

    bool Find(const K& key)
    {
        Node* cur = _root;
        while (cur)
        {
            if (cur->_key < key)
            {
                cur = cur->_right;
            }
            else if (cur->_key > key)
            {
                cur = cur->_left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    bool Erase(const K& key)
    {
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur)
        {
            if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                //找到了
                //1.左为空
                //2.右为空
                //3.左右都不为空
                if (cur->_left == nullptr)
                {
                    if (parent->_right == cur)
                    {
                        parent->_right = cur->_right;
                        delete cur;
                    }
                    else if (parent->_left == cur)
                    {
                        parent->_left = cur->_right;
                        delete cur;
                    }
                }
                else if (cur->_right == nullptr)
                {
                    if (parent->_left == cur)
                    {
                        parent->_left = cur->_left;
                        delete cur;
                    }
                    else
                    {
                        parent->_right = cur->_left;
                        delete cur;
                    }
                }
                else
                {
                    Node* rightMinParent = cur;
                    Node* rightMin = cur->_right;
                    while (rightMin->_left)
                    {
                        rightMinParent = rightMin;//8
                        rightMin = rightMin->_left;
                    }
                    cur->_key = rightMin->_key;
                    //转换成删rightmin 因为rightmin是左为空 父亲指向他的右
                    if(rightMin == rightMinParent -> _left)
                        rightMinParent->_left = rightMin -> _right;
                    else
                        rightMinParent->_left = rightMin->_right;
                    //转换成删除rightMin
                    delete rightMin;
                }
                return true;
            }
        }
        return false;
    }

private:
    Node* _root = nullptr;
};

void TestBSTree()
{
    BTree<int> t;
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
    for (auto e : a)
    {
        t.Insert(e);
    }
    t.InOrder();
    t.Erase(7);
    t.Erase(2);
    t.InOrder();
    t.Erase(1);
    t.Erase(8);
    t.InOrder();
}

//删除 左子树的最右节点 右子树的最左节点
//左为空，父亲指向我的右 右为空，父亲指向我的左

//搜索使用场景:1.key的模型 判断在不在
//2.key/value的模型 通过key找对应的value
