//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node (for storing node + HD)
struct QNode {
    struct Node* node;
    int hd;
};

// Queue
struct Queue {
    struct QNode arr[MAX];
    int front, rear;
};

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Initialize Queue
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QNode dequeue(struct Queue* q) {
    struct QNode temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    int map[200][MAX];   // store nodes
    int count[200] = {0};

    int offset = 100;    // to handle negative HD
    int min = 100, max = 100;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = curr->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (curr->left)
            enqueue(&q, curr->left, temp.hd - 1);

        if (curr->right)
            enqueue(&q, curr->right, temp.hd + 1);
    }

    // Print result
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

// Driver Code
int main() {
    // Construct tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    verticalOrder(root);

    return 0;
}