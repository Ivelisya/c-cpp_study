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
        Node *current = _root;
        while (current)
        {
            if (current->_kv.first < kv.first)
            {
                parent = current;
                current = current->_right;
            }
            else if (current->_kv.first > kv.first)
            {
                parent = current;
                current = current->_left;
            }
            else
            {
                return false; // Key already exists
            }
        }

        Node *newNode = new Node(kv);
        if (parent->_kv.first < kv.first)
        {
            parent->_right = newNode;
        }
        else
        {
            parent->_left = newNode;
        }
        newNode->_parent = parent;
        newNode->_col = RED;

        BalanceAfterInsert(newNode);

        return true;
    }

    Node *Find(const K &key) const
    {
        Node *current = _root;
        while (current)
        {
            if (current->_kv.first < key)
            {
                current = current->_right;
            }
            else if (current->_kv.first > key)
            {
                current = current->_left;
            }
            else
            {
                return current;
            }
        }
        return nullptr;
    }

private:
    Node *_root = nullptr;

    void BalanceAfterInsert(Node *node)
    {
        while (node->_parent && node->_parent->_col == RED)
        {
            Node *parent = node->_parent;
            Node *grandparent = parent->_parent;

            if (grandparent && parent == grandparent->_left)
            {
                Node *uncle = grandparent->_right;

                // Case 1: Uncle is RED
                if (uncle && uncle->_col == RED)
                {
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandparent->_col = RED;
                    node = grandparent;
                }
                else
                {
                    // Case 3: Right-Left
                    if (node == parent->_right)
                    {
                        RotateL(parent);
                        node = parent;
                        parent = node->_parent;
                    }

                    // Case 2: Left-Left
                    RotateR(grandparent);
                    parent->_col = BLACK;
                    grandparent->_col = RED;
                }
            }
            else if (grandparent)
            {
                Node *uncle = grandparent->_left;

                // Case 1: Uncle is RED
                if (uncle && uncle->_col == RED)
                {
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandparent->_col = RED;
                    node = grandparent;
                }
                else
                {
                    // Case 3: Left-Right
                    if (node == parent->_left)
                    {
                        RotateR(parent);
                        node = parent;
                        parent = node->_parent;
                    }

                    // Case 2: Right-Right
                    RotateL(grandparent);
                    parent->_col = BLACK;
                    grandparent->_col = RED;
                }
            }
        }

        _root->_col = BLACK;
    }

    void RotateL(Node *node)
    {
        if (!node || !node->_right)
            return;

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
        if (!node || !node->_left)
            return;

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
