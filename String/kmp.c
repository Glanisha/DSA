#include <stdio.h> 
#include <string.h>
int f[100];

void pattern_table(char p[], int m){
    int i=1, j=0; 
    f[0]=0;
    
    while(i<m){
        if(p[i]==p[j]){
            f[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j==0){
                f[i]=0;
                i++;
            }
            else{
                j=f[j-1];
            }
        }
    }
}

void kmp(char t[], char p[], int n, int m){
    pattern_table(p, m);
    
    int i=0, j=0;
    
    while(i<n){
        if(t[i]==p[j]){
            if(j==m-1){
                printf("Pattern found at %d", i-j);
                return; 
            }
            i++; 
            j++;
        }
        else{
             if(j==0){
                 i++;
             }
             else{
                 j=f[j-1];
             }
        }
    }
    printf("Pattern not found");
}

int main(){
    int n, m ; 
    char t[100],p[100];
    
    printf("Enter the text:");
    scanf("%s", t);
    printf("\nEnter the pattern:");
    scanf("%s", p);
    
    n=strlen(t);
    m=strlen(p);
    
    kmp(t, p, n, m);
    
    return 0;
}