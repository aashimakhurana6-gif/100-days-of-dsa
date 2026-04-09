//Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Topological Sort using Kahn's Algorithm
void topologicalSort(int graph[MAX][MAX], int V) {
    int indegree[MAX] = {0};

    // Step 1: Calculate indegree of each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Push all vertices with indegree 0 into queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("Topological Order: ");

    int count = 0;

    // Step 3: Process queue
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Step 4: Reduce indegree of adjacent vertices
        for (int j = 0; j < V; j++) {
            if (graph[node][j] == 1) {
                indegree[j]--;

                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    // Step 5: Check for cycle
    if (count != V) {
        printf("\nGraph has a cycle! No Topological Sorting possible.\n");
    }
}

// Driver code
int main() {
    int V = 6;

    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph, V);

    return 0;
}