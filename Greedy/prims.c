#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int numberOfVertices;
    int graph[MAX][MAX];
    int selected[MAX];
    int parent[MAX];
    int minEdgeWeight[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &numberOfVertices);

    printf("Enter the adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < numberOfVertices; i++) {
        for (int j = 0; j < numberOfVertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < numberOfVertices; i++) {
        minEdgeWeight[i] = INT_MAX;
        selected[i] = 0;
    }

    minEdgeWeight[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numberOfVertices - 1; count++) {
        int min = INT_MAX, minIndex;

        for (int v = 0; v < numberOfVertices; v++) {
            if (!selected[v] && minEdgeWeight[v] < min) {
                min = minEdgeWeight[v];
                minIndex = v;
            }
        }

        selected[minIndex] = 1;

        for (int v = 0; v < numberOfVertices; v++) {
            if (graph[minIndex][v] && !selected[v] && graph[minIndex][v] < minEdgeWeight[v]) {
                parent[v] = minIndex;
                minEdgeWeight[v] = graph[minIndex][v];
            }
        }
    }

    printf("\nMinimum Spanning Tree (Edge - Weight):\n");
    for (int i = 1; i < numberOfVertices; i++) {
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
    }

    return 0;
}
