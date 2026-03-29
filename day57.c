//Convert a binary tree into its mirror image by swapping left and right children at every node.
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Mirror Function
void mirror(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Build Tree from Level Order (using array)
struct Node* buildTree(int arr[], int i, int n) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);

    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    // Convert to mirror
    mirror(root);

    // Print inorder of mirrored tree
    inorder(root);

    return 0;
}