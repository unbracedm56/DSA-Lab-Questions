#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(){
    int n;
    scanf("%d", &n);

    char str[n + 1];
    scanf("%s", str);

    int dp[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }

    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;

            if(str[i] == str[j]){
                if(len == 2){
                    dp[i][j] = 2;
                }else{
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
            }else{
                dp[i][j] = MAX(dp[i + 1][j], dp[i][j - 1]);
            }

        }
    }

    printf("%d", dp[0][n - 1]);
}