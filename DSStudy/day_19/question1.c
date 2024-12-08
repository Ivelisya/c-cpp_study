//
// Created by 20212 on 23/7/2024.
//
//求第k层节点的个数

//当前节点的叶子节点个数等于左子树叶子节点加右子树叶子节点个数
//分治算法 把大问题分解成小问题，小问题进一步分解，直到不可以再继续分解
//当前树的第k层可以转化为左右子树的第k-1层


#if 0
int BinaryTreeLevelKSize(BTNode *root,int k){
    if(root == NULL){
        return 0;
    }
    if(k == 1){
        return 1;
    }
    return BinaryTreeLevelKSize(root -> _left,k-1) + BinaryTreeLevelKSize(root -> _right,k-1);
}
#endif