#include "stdio.h"
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

struct TreeNode* createNode (int value) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node != NULL) {
        node->val = value;
        node->right = NULL;
        node->left = NULL;
    }
    return node;
}

void insert (struct TreeNode *root, int value) {
    if (root->val > value) {
        if (root->left != NULL) {
            insert(root->left, value);
        } else {
            root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            root->left = createNode(value);
        }
    } else if (root->val < value) {
        if (root->right != NULL) {
            insert(root->right, value);
        } else {
            root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            root->right = createNode(value);
        }
    } else {
        return;
    }
}

void delete (struct TreeNode *root, int value) {


}

void printTree (struct TreeNode *root) {
    if (root->left != NULL) {
        printTree(root->left);
    }
    printf(" <%d> ", root->val);
    if (root->right != NULL) {
        printTree(root->right);
    }
}

int main () {
    struct TreeNode *root = createNode(10);

    insert(root, 5);
    insert(root, 11);
    insert(root, 2);
    insert(root, 4);
    printTree(root);


    return 0;
}
