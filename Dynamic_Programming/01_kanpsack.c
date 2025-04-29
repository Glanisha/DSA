#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

int knapsack(int n, int cap, int wt[], int val[], int dp[n+1][cap+1]) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= cap; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;  
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= cap; j++) {
            if(wt[i-1] <= j) {
                dp[i][j] = (dp[i-1][j] > (val[i-1] + dp[i-1][j-wt[i-1]])) ? dp[i-1][j] : (val[i-1] + dp[i-1][j-wt[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
    
    return dp[n][cap]; 
}

void printSelectedItems(int n, int cap, int wt[], int dp[n+1][cap+1]) {
    printf("\nSelected items: ");
    int w = cap;

    for(int i = n; i > 0; i--) {
        if(dp[i][w] != dp[i-1][w]) { 
            printf("Item %d (Weight: %d, Value: %d) ", i, wt[i-1], dp[i][w] - dp[i-1][w]);
            w -= wt[i-1]; 
        }
    }
    printf("\n");
}

int main(){
    int n;

    printf("Enter the number of items that can be added: ");
    scanf("%d", &n);
    
    int wt[n], val[n]; 
    int capacity; 
    
    printf("Enter the total capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("\nEnter the weights of the items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("\nEnter the value of the items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    int dp[n+1][capacity+1];

    int result = knapsack(n, capacity, wt, val, dp);
    printf("The maximum value that can be obtained is: %d\n", result);

    printSelectedItems(n, capacity, wt, dp);
    
    return 0;
}
