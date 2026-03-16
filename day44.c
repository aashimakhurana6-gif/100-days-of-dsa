//Perform inorder, preorder, and postorder traversals of a given binary tree.
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

/* Traversals */

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    int n,i;
    scanf("%d",&n);

    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[0] == -1) return 0;

    Queue q;
    q.front=0; q.rear=-1;

    Node* root = createNode(arr[0]);
    enqueue(&q,root);

    i=1;

    while(i<n && !isEmpty(&q)){
        Node* curr = dequeue(&q);

        if(arr[i] != -1){
            curr->left = createNode(arr[i]);
            enqueue(&q,curr->left);
        }
        i++;

        if(i<n && arr[i] != -1){
            curr->right = createNode(arr[i]);
            enqueue(&q,curr->right);
        }
        i++;
    }

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}
