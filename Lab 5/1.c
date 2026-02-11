#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int a1, b1, a2, b2;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

    int prefix[n][m];
    prefix[0][0] = matrix[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            prefix[i][j] = matrix[i][j];
            if(i > 0) prefix[i][j] += prefix[i - 1][j];
            if(j > 0) prefix[i][j] += prefix[i][j - 1];
            if(i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    a1--; b1--; a2--; b2--;

    int sum = prefix[a2][b2];
    if(a1 > 0){
        sum -= prefix[a1 - 1][b2];
    }
    if(b1 > 0){
        sum -= prefix[a2][b1 - 1];
    }
    if(a1 > 0 && b1 > 0){
        sum += prefix[a1 - 1][b1 - 1];
    }
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", prefix[i][j]);
        }
        printf("\n");
    }
    printf("Sum = %d", sum);
}