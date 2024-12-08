//
// Created by 20212 on 23/7/2024.
//
//销毁采用后序销毁
//BTNode *BinaryTreeFind(BTNode*root,BTDataType x){
//    if(root == NULL){
//        return NULL;
//    }
//    if(root -> _data == x){
//        return root;
//    }
//    BTNode* node = BinaryTreeFind(root -> _left,x){
//        if(node){
//            return node;
//        }
//    }
//    BTNode* node = BinaryTreeFind(root -> _right,x){
//        if(node){
//            return node;
//        }
//    }
//    return NULL;
//}

//void DestoryTree(BTNode* root){
//    if (root == NULL){
//        return;
//    }
//    DestoryTree( root -> _left);
//    DestoryTree(root -> _right);
//    free(root);
//}
//二叉树的层序遍历 使用队列

//1.根先进队列
//2.迭代 -> 队列不为空，出队头数据，同时把出的节点的左右孩子带进去
//3.直到队列为空结束
//上一层节点带下一层节点进队列 一层一层走，队列先进先出


//层序遍历，第一层出来带第二层，打印出来可能是多层的