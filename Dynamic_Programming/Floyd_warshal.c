#include <stdio.h>

#define INF 99999

int main() {
    int v; 
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    
    int graph[v][v];
    
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Original adjacency matrix:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            printf("%7d ", graph[i][j]);
        }
        printf("\n");
    }
    
    int distance[v][v];
    
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            distance[i][j] = graph[i][j];
        }
    }
    
    for(int k = 0; k < v; k++) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    
    printf("Distance matrix:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            printf("%7d ", distance[i][j]);
        }
        printf("\n");
    }
}
