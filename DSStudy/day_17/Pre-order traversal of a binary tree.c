//
// Created by 20212 on 15/7/2024.
//
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if 0
int TreeSize(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + TreeSize(root -> left) + TreeSize(root -> right);
}
void _preorderTraversal(struct TreeNode*root,int * array,int* pi){
    if(root == NULL){
        return;
    }
    //...
    array[(*pi)] = root->val;
    ++(*pi);
    _preorderTraversal(root -> left,array,pi);
    _preorderTraversal(root -> right,array,pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    int *arr = (int*)malloc(sizeof(int)*size);
    int i = 0;
    int * pi = &i;
    _preorderTraversal(root,arr,pi);
    *returnSize = size;
    return arr;
}
#endif