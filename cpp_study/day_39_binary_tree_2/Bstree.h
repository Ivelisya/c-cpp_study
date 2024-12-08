//
// Created by 20212 on 24-11-5.
//
#include <iostream>
using namespace std;
#include <string>
template <class K, class V>
struct BStreeNode //Binary Search Tree Node
{
    BStreeNode<K,V>* _left;
    BStreeNode<K,V>* _right;

    K _key;
    V _val;

    BStreeNode(const K&key):_left(nullptr),_right(nullptr),_key(key)
,_val(value)
    {}

};
//如果
//如何解决？ 平衡树
//1.AVLtree
//2.红黑树

//搜索树的修改
//搜素树中的key是不可以被修改的
//如果是kv模型的树，可以修改value，但是不能修改key