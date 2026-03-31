//Construct a binary tree from given inorder and postorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Search in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build Tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    
    // Base case
    if (start > end)
        return NULL;

    // Pick root from postorder
    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = newNode(curr);

    // If only one node
    if (start == end)
        return root;

    // Find index in inorder
    int pos = search(inorder, start, end, curr);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return root;
}

// Preorder Traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main
int main() {
    int n = 5;

    int inorder[]   = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder Traversal:\n");
    preorder(root);

    return 0;
}
