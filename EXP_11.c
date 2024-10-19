#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices in the graph

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Array to mark visited nodes
int queue[MAX], front = -1, rear = -1; // Queue for BFS

// Function to add an edge to the adjacency matrix (directed graph)
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1; // Add a directed edge from node u to node v
}

// BFS function
void bfs(int startVertex, int n) {
    printf("BFS Traversal: ");
    front = rear = 0; // Initialize the queue
    queue[rear] = startVertex;
    visited[startVertex] = 1; // Mark the start vertex as visited

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Explore the adjacent vertices of currentVertex
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1; // Mark the adjacent vertex as visited
            }
        }
    }
    printf("\n");
}

// DFS function using recursion
void dfs(int vertex, int n) {
    printf("%d ", vertex);
    visited[vertex] = 1; // Mark the current vertex as visited

    // Recursively visit all adjacent unvisited vertices
    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

// Driver code to demonstrate BFS and DFS
int main() {
    int n, edges, u, v, startVertex, choice;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Initialize the adjacency matrix to 0 (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) where there is an edge from u to v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    while (1) {
        printf("\nGraph Traversal Menu:\n");
        printf("1. BFS\n");
        printf("2. DFS\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        // Reset the visited array
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }

        printf("Enter the starting vertex: ");
        scanf("%d", &startVertex);

        switch (choice) {
            case 1:
                bfs(startVertex, n);
                break;
            case 2:
                printf("DFS Traversal: ");
                dfs(startVertex, n);
                printf("\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
