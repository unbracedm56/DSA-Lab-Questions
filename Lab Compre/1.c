#include <stdio.h>

int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int dp[r][c];
    dp[0][0] = 1;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(i == 0 && j == 0) continue;
            if(matrix[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }

            int up = 0, left = 0;
            if(i > 0 && matrix[i - 1][j] == 0){
                up = dp[i - 1][j];
            }
            if(j > 0 && matrix[i][j - 1] == 0){
                left = dp[i][j - 1];
            }

            dp[i][j] = left + up;
        }
    }

    printf("%d", dp[r - 1][c - 1]);
}