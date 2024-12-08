//
// Created by 20212 on 15/7/2024.
//
//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

#if 0
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)
    {    return NULL;
    }
    else{
        struct TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;

        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
}
#endif