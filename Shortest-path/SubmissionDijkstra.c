#include <stdio.h>
#include <limits.h>
#define V 100 // Maximum number of vertices

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int visited[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src, int vertices) {
    int dist[V];         // Shortest distance from src to each vertex
    int visited[V] = {0}; // Visited vertices

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int vertices, src;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the graph in adjacency matrix form (0 for no edge):\n");
    int graph[V][V];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, vertices);

    return 0;
}
