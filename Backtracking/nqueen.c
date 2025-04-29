#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

int col[100];

bool isSafe(int q, int c){
   for(int i = 1; i <= q - 1; i++) {
        if(c == col[i] || abs(i - q) == abs(col[i] - c)) {
            return 0; 
        }
    }
    return 1; 
}
void nqueen(int q, int n){
    int c; 
    for(c=1; c<=n; c++){
        if(isSafe(q, c)){
            col[q]=c;
            if(q==n){
              for(int i = 1; i <= n; i++) {
                    printf("%d ", col[i]);
                }
                printf("\n");
            }
            else{
                nqueen(q+1, n);
            }
        }
    }
}

int main(){
    int q, n;
    printf("Enter the number of queens:");
    scanf("%d", &n); 
    
    nqueen(1, n);
    
    return 0;
}