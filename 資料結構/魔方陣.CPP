#include <stdio.h> 
#include <stdlib.h> 

#define N 9 

int main(void) { 
    int square[N+1][N+1] = {0}; 

    int i = 0; 
    int j = (N+1) / 2; 
    int key;
    for(key = 1; key <= N*N; key++) { 
        if((key % N) == 1) 
            i++; 
        else { 
            i--; 
            j++; 
        } 

        if(i == 0) 
            i = N; 
        if(j > N) 
            j = 1; 

        square[i][j] = key; 
    } 

    int m, n;
    for(m = 1; m <= N; m++) { 
        for(n = 1; n <= N; n++) 
            printf("%2d ", square[m][n]);
        printf("\n");
    } 

    return 0; 
} 