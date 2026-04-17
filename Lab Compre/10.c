#include <stdio.h>
#include <limits.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int cuts[m + 2];
    cuts[0] = 0;
    cuts[m + 1] = n;
    for(int i = 1; i <= m; i++){
        scanf("%d", &cuts[i]);
    }

    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < m + 1 - i; j++){
            if(cuts[j] > cuts[j + 1]){
                int temp = cuts[j];
                cuts[j] = cuts[j + 1];
                cuts[j + 1] = temp;
            }
        }
    }

    int dp[m + 2][m + 2];

    for(int i = 0; i < m + 2; i++){
        for(int j = 0; j < m + 2; j++){
            dp[i][j] = 0;
        }
    }

    for(int len = 2; len < m + 2; len++){
        for(int i = 0; i + len < m + 2; i++){
            int j = i + len;
            dp[i][j] = INT_MAX;

            for(int k = i + 1; k < j; k++){
                int cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                }
            }

            if(dp[i][j] == INT_MAX){
                dp[i][j] = 0;
            }
        }
    }

    printf("%d", dp[0][m + 1]);
}