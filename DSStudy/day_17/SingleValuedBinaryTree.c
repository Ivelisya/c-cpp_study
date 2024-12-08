//
// Created by 20212 on 15/7/2024.
//
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。
//
//
#if 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root) {
    if(root == NULL)
        return true;
    //当前树
    if(root -> left && root -> val != root -> left ->val){
        return false;
    }
    if(root -> right && root -> val != root -> right ->val){
        return false;}
    //递归判断左右子树
    //实质是一种前序判断
    return isUnivalTree(root -> left) && isUnivalTree(root -> right);
}
#endif