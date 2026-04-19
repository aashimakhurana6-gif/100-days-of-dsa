//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v, int w) {
    struct Node* node1 = createNode(v, w);
    node1->next = adj[u];
    adj[u] = node1;

    struct Node* node2 = createNode(u, w);
    node2->next = adj[v];
    adj[v] = node2;
}

// Find minimum key vertex
int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

// Prim's Algorithm
int primMST(int n) {
    int key[MAX], visited[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // Start from node 1
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;
        totalWeight += key[u];

        // Traverse adjacency list
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
            }
            temp = temp->next;
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("%d\n", primMST(n));

    return 0;
}