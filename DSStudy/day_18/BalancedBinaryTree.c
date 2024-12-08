//
// Created by 20212 on 17/7/2024.
//
//每个节点的左右两个子树的高度差的绝对值不超过1
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int TreeDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
//高度被重复计算了

//我们现在采用的是一种前序判断
//导致计算高度存在大量的重复

//如果我们使用后序判读 就可以解决这个问题
bool isBalanced(struct TreeNode* root) {
    if (root == NULL)

        return true;
    int treeRight = TreeDepth(root->right);
    int treeLeft = TreeDepth(root->left);
    return abs(treeRight - treeLeft) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
