//Level Order Traversal
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

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void enqueue(Queue *q, Node* node){
    q->arr[++q->rear] = node;
}

Node* dequeue(Queue *q){
    return q->arr[q->front++];
}

int isEmpty(Queue *q){
    return q->front > q->rear;
}

/* Level Order Traversal */
void levelOrder(Node* root){
    if(root == NULL) return;

    Queue q;
    q.front = 0; q.rear = -1;

    enqueue(&q, root);

    while(!isEmpty(&q)){
        Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if(curr->left)
            enqueue(&q, curr->left);

        if(curr->right)
            enqueue(&q, curr->right);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[0] == -1) return 0;

    Queue q;
    q.front = 0; q.rear = -1;

    Node* root = createNode(arr[0]);
    enqueue(&q, root);

    i = 1;

    // Construct Tree
    while(i<n && !isEmpty(&q)){
        Node* curr = dequeue(&q);

        if(arr[i] != -1){
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if(i<n && arr[i] != -1){
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    // Level Order Traversal
    levelOrder(root);

    return 0;
}