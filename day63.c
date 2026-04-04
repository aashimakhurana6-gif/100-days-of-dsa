// Perform DFS starting from a given source vertex using recursion.
#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = v;

    graph->adjList = (struct Node**)malloc(v * sizeof(struct Node*));

    for (int i = 0; i < v; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

// DFS function (recursive)
void DFS(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adjList[v];

    while (temp) {
        int adjVertex = temp->data;

        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int s;
    scanf("%d", &s);  // starting vertex

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(graph, s, visited);

    return 0;
}