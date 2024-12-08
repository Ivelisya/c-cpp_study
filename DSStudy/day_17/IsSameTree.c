//
// Created by 20212 on 15/7/2024.
//
//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
#if 0
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL && q != NULL)
        return false;
    if(q == NULL && p != NULL)
        return false;
    if(p -> val != q ->val)
        return false;
    return isSameTree(p -> left,q -> left) && isSameTree(p -> right,q -> right);
}
#endif