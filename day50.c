//BST Search
#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    // Base case
    if (root == NULL || root->val == key) {
        return root;
    }

    // Search in left subtree
    if (key < root->val) {
        return searchBST(root->left, key);
    }
    
    // Search in right subtree
    return searchBST(root->right, key);
}