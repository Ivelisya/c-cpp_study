//
// Created by 20212 on 29/6/2024.
//
#include <stdio.h>
#include <stdlib.h> // Needed for malloc

typedef char BTDataType;

typedef struct BinaryTreeNode {
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
} BTNode;

void PrevOrder(BTNode* root) {
    if (root == NULL){
        printf("NULL ");
        return;}
    printf("%c ", root->_data); // Changed %d to %c for char data
    PrevOrder(root->_left);
    PrevOrder(root->_right);
}

void InOrder(BTNode* root) {
    if (root == NULL){
        printf("NULL ");
        return;}
     // Changed %d to %c for char data
    InOrder(root->_left);
    printf("%c ", root->_data);
    InOrder(root->_right);
}
void PostOrder(BTNode* root) {
    if (root == NULL){
        printf("NULL ");
        return;}
     // Changed %d to %c for char data
    PostOrder(root->_left);
    PostOrder(root->_right);
    printf("%c ", root->_data);
    
}

int TreeSize(BTNode* root) {
    if (root == NULL)
        return 0;
    else 
        return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
BTNode* CreateNode(BTDataType x) {
    BTNode* node = (BTNode*)malloc(sizeof(BTNode)); // Corrected BTnode to BTNode
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}

int main() {
    BTNode* A = CreateNode('A');
    BTNode* B = CreateNode('B');
    BTNode* C = CreateNode('C');
    BTNode* D = CreateNode('D');
    BTNode* E = CreateNode('E');

    A->_left = B;
    A->_right = C;
    B->_left = D;
    B->_right = E;

    printf("Preorder traversal: \n");
    PrevOrder(A);
    printf("\n");
    InOrder(A);
    printf("\n");
    PostOrder(A);
    printf("\n");

    printf("Tree size: %d\n", TreeSize(A));

    // Don't forget to free allocated memory when done
    free(A);
    free(B);
    free(C);
    free(D);
    free(E);

    return 0;
}
