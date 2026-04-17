#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int dp[k + 1][n];
    for(int i = 0; i <= k; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < n; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= k; i++){
        int best = -A[0];
        for(int j = 1; j < n; j++){
            dp[i][j] = MAX(dp[i][j - 1], A[j] + best);
            best = MAX(best, dp[i - 1][j - 1] - A[j]);
        }
    }

    printf("%d", dp[k][n - 1]);
}