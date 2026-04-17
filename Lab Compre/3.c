#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    char source[n + 1], target[m + 1];
    scanf("%s", source);
    scanf("%s", target);

    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= m; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(source[i - 1] == target[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d", dp[n][m]);
}