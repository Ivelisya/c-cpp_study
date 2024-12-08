#pragma once
#include <utility>
using namespace std;

enum Colour
{
    BLACK,
    RED,
};

template <class K, class V>
class RBTreeNode
{
public:
    RBTreeNode(const pair<K, V> &kv)
        : _kv(kv), _left(nullptr), _right(nullptr), _parent(nullptr), _col(RED) {}

    RBTreeNode<K, V> *_left;
    RBTreeNode<K, V> *_right;
    RBTreeNode<K, V> *_parent;

    pair<K, V> _kv;
    Colour _col;
};

template <class K, class V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;

public:
    bool Insert(const pair<K, V> &kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv);
            _root->_col = BLACK;
            return true;
        }

        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (cur->_kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false; // Key already exists
            }
        }

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

        cur->_col = RED;

        // Balance the tree after insertion
        while (parent && parent->_col == RED)
        {
            Node *grandfather = parent->_parent;
            if (grandfather && grandfather->_left == parent)
            {
                Node *uncle = grandfather->_right;

                // Case 1: Uncle exists and is RED
                if (uncle && uncle->_col == RED)
                {
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandfather->_col = RED;
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else
                {
                    // Case 3: Right-Left situation
                    if (cur == parent->_right)
                    {
                        RotateL(parent);
                        swap(parent, cur);
                    }
                    // Case 2: Left-Left situation
                    RotateR(grandfather);
                    grandfather->_col = RED;
                    parent->_col = BLACK;
                    break;
                }
            }
            else if (grandfather)
            {
                Node *uncle = grandfather->_left;

                // Symmetric to the above
                if (uncle && uncle->_col == RED)
                {
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandfather->_col = RED;
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else
                {
                    if (cur == parent->_left)
                    {
                        RotateR(parent);
                        swap(parent, cur);
                    }
                    RotateL(grandfather);
                    grandfather->_col = RED;
                    parent->_col = BLACK;
                    break;
                }
            }
        }

        _root->_col = BLACK;
        return true;
    }

    Node *Fond(const K &key)
    {
        Node *cur = _root;
        while (cur)
        {
            if (cur->_kv.first < key)
            {
                cur = cur->_right;
            }
            else if (cur->_kv.first > key)
            {
                cur = cur->_left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }

private:
    Node *_root = nullptr;

    void RotateL(Node *node)
    {
        Node *rightChild = node->_right;
        node->_right = rightChild->_left;
        if (rightChild->_left)
        {
            rightChild->_left->_parent = node;
        }
        rightChild->_parent = node->_parent;
        if (node->_parent == nullptr)
        {
            _root = rightChild;
        }
        else if (node == node->_parent->_left)
        {
            node->_parent->_left = rightChild;
        }
        else
        {
            node->_parent->_right = rightChild;
        }
        rightChild->_left = node;
        node->_parent = rightChild;
    }

    void RotateR(Node *node)
    {
        Node *leftChild = node->_left;
        node->_left = leftChild->_right;
        if (leftChild->_right)
        {
            leftChild->_right->_parent = node;
        }
        leftChild->_parent = node->_parent;
        if (node->_parent == nullptr)
        {
            _root = leftChild;
        }
        else if (node == node->_parent->_left)
        {
            node->_parent->_left = leftChild;
        }
        else
        {
            node->_parent->_right = leftChild;
        }
        leftChild->_right = node;
        node->_parent = leftChild;
    }
};
