#include <stdio.h>
#define MAX 20

int G[MAX][MAX];
int x[MAX];
int n;

int issafe(int k, int c) {
    for (int i = 0; i < n; i++) { 
        if (G[k][i] == 1 && x[i] == c) {
            return 0; 
        }
    }
    return 1;
}

void GraphColor(int v, int m) {
    if (v == n) { 
        printf("Solution Vector: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
        return;
    }

    for (int c = 1; c <= m; c++) { 
        if (issafe(v, c)) {
            x[v] = c;
            GraphColor(v + 1, m); 
            x[v] = 0; 
        }
    }
}

int main() {
    int m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        x[i] = 0; 
    }

    printf("All possible solutions:\n");
    GraphColor(0, m);

    return 0;
}