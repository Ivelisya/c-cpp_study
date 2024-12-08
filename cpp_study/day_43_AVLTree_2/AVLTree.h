#ifndef AVLTREE_H
#define AVLTREE_H

#pragma once
#include <utility> // 使用 std::pair
using namespace std;

template <class K, class V>
struct AVLTreeNode
{
    AVLTreeNode<K, V> *_left;
    AVLTreeNode<K, V> *_right;
    AVLTreeNode<K, V> *_parent;
    int _bf; // 平衡因子

    pair<K, V> _kv;

    AVLTreeNode(const pair<K, V> &kv)
        : _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0), _kv(kv) {}
};

template <class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;

public:
    AVLTree() : _root(nullptr) {}

    ~AVLTree()
    {
        Destroy(_root);
    }

    bool Insert(const pair<K, V> &kv)
    {
        // 插入节点
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }

        Node *parent = nullptr;
        Node *cur = _root;

        // 查找插入位置
        while (cur)
        {
            if (cur->_kv.first > kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (cur->_kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false; // 重复键，插入失败
            }
        }

        // 创建新节点并连接
        cur = new Node(kv);
        if (parent->_kv.first < kv.first)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        cur->_parent = parent;

        // 更新平衡因子并调整平衡
        while (parent)
        {
            if (cur == parent->_right)
            {
                parent->_bf++;
            }
            else
            {
                parent->_bf--;
            }

            if (parent->_bf == 0)
            {
                break; // 父节点平衡，停止调整
            }
            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                cur = parent;
                parent = parent->_parent; // 向上更新
            }
            else // parent->_bf == 2 或 -2，需旋转
            {
                if (parent->_bf == 2)
                {
                    if (cur->_bf == 1) // LL
                    {
                        RotateL(parent);
                    }
                    else if (cur->_bf == -1) // RL
                    {
                        RotateRL(parent);
                    }
                }
                else if (parent->_bf == -2)
                {
                    if (cur->_bf == -1) // RR
                    {
                        RotateR(parent);
                    }
                    else if (cur->_bf == 1) // LR
                    {
                        RotateLR(parent);
                    }
                }
                break; // 调整后子树高度恢复，停止
            }
        }
        return true;
    }

private:
    Node *_root;

    void Destroy(Node *node)
    {
        if (node)
        {
            Destroy(node->_left);
            Destroy(node->_right);
            delete node;
        }
    }

    void RotateL(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;

        parent->_right = subRL;
        if (subRL)
            subRL->_parent = parent;
        subR->_left = parent;

        Node *ppNode = parent->_parent;
        parent->_parent = subR;

        if (_root == parent)
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else
        {
            if (ppNode->_left == parent)
            {
                ppNode->_left = subR;
            }
            else
            {
                ppNode->_right = subR;
            }
            subR->_parent = ppNode;
        }

        // 更新平衡因子
        parent->_bf = subR->_bf = 0;
    }

    void RotateR(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;

        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;
        subL->_right = parent;

        Node *ppNode = parent->_parent;
        parent->_parent = subL;

        if (_root == parent)
        {
            _root = subL;
            subL->_parent = nullptr;
        }
        else
        {
            if (ppNode->_left == parent)
            {
                ppNode->_left = subL;
            }
            else
            {
                ppNode->_right = subL;
            }
            subL->_parent = ppNode;
        }

        // 更新平衡因子
        parent->_bf = subL->_bf = 0;
    }

    void RotateRL(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;

        int bf = subRL->_bf;
        RotateR(parent->_right);
        RotateL(parent);

        if (bf == -1)
        {
            parent->_bf = 0;
            subR->_bf = 1;
            subRL->_bf = 0;
        }
        else if (bf == 1)
        {
            parent->_bf = -1;
            subR->_bf = 0;
            subRL->_bf = 0;
        }
        else if (bf == 0)
        {
            parent->_bf = 0;
            subR->_bf = 0;
            subRL->_bf = 0;
        }
    }

    void RotateLR(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;

        int bf = subLR->_bf;
        RotateL(subL);
        RotateR(parent);

        if (bf == 1)
        {
            parent->_bf = 0;
            subL->_bf = -1;
            subLR->_bf = 0;
        }
        else if (bf == -1)
        {
            parent->_bf = 1;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
        else if (bf == 0)
        {
            parent->_bf = 0;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
    }
};

#endif // AVLTREE_H
