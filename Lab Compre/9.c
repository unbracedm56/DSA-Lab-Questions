#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    char seqA[n + 1], seqB[m + 1];
    scanf("%s", seqA);
    scanf("%s", seqB);

    int dp[n + 1][m + 1];

    for(int j = 1; j <=m; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <=n; i++){
        dp[i][0] = i;
    }
    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(seqA[i - 1] == seqB[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = 1 + MIN(MIN(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }

    printf("%d", dp[n][m]);

}