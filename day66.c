//Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to add edge
void addEdge(int adj[][100], int u, int v) {
    adj[u][v] = 1;
}

// DFS function to detect cycle
bool dfs(int node, int V, int adj[][100], bool visited[], bool recStack[]) {
    
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            
            // If not visited → recurse
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            }
            // If already in recursion stack → cycle found
            else if (recStack[i]) {
                return true;
            }
        }
    }

    // Remove node from recursion stack
    recStack[node] = false;
    return false;
}

// Function to check cycle in graph
bool isCycle(int V, int adj[][100]) {
    bool visited[100] = {false};
    bool recStack[100] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

// Driver Code
int main() {
    int V = 4;
    int adj[100][100] = {0};

    // Example graph
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1); // cycle here

    if (isCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}