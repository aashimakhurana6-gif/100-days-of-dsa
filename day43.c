//Construct a Binary Tree from the given level-order traversal.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Queue {
    Node* arr[100];
    int front, rear;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void enqueue(Queue *q, Node* node) {
    q->arr[++q->rear] = node;
}

Node* dequeue(Queue *q) {
    return q->arr[q->front++];
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void inorder(Node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(arr[0] == -1)
        return 0;

    Queue q;
    q.front = 0;
    q.rear = -1;

    Node* root = createNode(arr[0]);
    enqueue(&q, root);

    i = 1;

    while(i < n && !isEmpty(&q)) {
        Node* current = dequeue(&q);

        if(arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        if(i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    inorder(root);

    return 0;
}