#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main(){
    int n;
    scanf("%d", &n);

    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int dp[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = A[i];
    }

    for(int len = 1; len < n; len++){
        for(int i = 0; len + i < n; i++){
            int j = len + i;

            int x = (i + 2 <= j) ? dp[i + 2][j] : 0;
            int y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            int z = (i <= j - 2) ? dp[i][j - 2] : 0;

            dp[i][j] = MAX(A[i] + MIN(x, y), A[j] + MIN(y, z));
        }
    }

    printf("%d", dp[0][n - 1]);
}