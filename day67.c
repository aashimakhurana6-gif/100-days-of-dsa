// Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFS(temp->data);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    push(v);
}

// Topological Sort
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Driver code
int main() {
    int V = 6;

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Graph edges
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(V);

    return 0;
}