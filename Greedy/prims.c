#include <stdio.h> 

#define INF 9999
#define MAX 100

int v; 
int graph[MAX][MAX];

int minimum(int dist[], int visited[]){
    int min=INF, min_index=-1;
    
    for(int i =0; i<v; i++){
        if(!visited[i] && dist[i]<min){
            min=dist[i];
            min_index=i;
        }
    }
    
    return min_index;
}

void prims(){
    int dist[MAX], parent[MAX], visited[MAX];
    for(int i=0; i<v; i++){
        dist[i]=INF;
        visited[i]=0;
    }
    
    dist[0]=0;
    parent[0]=-1;
    
    for(int i=0; i<v-1; i++){
        int min_index=minimum(dist, visited);
        visited[min_index]=1;
        
        for(int j=0; j<v; j++){
            if(graph[min_index][j] && !visited[j] && graph[min_index][j] < dist[j]){
                parent[j]=min_index;
                dist[j]=graph[min_index][j];
            }
        }
    }
     int cost = 0;
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < v; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        cost += graph[i][parent[i]];
    }
    printf("Total cost of the MST: %d\n", cost);
}

int main(){
    printf("Enter the number of vertices:");
    scanf("%d", &v);
    
    printf("Enter the adjacency matrix: ");
for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    prims();
    return 0;
}
