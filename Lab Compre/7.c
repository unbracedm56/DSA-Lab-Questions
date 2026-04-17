#include <stdio.h>
#include <stdbool.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    char str[n + 1], pattern[m + 1];
    scanf("%s", str);
    scanf("%s", pattern);

    bool dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;

    for(int j = 1; j<= m; j++){
        if(pattern[j - 1] == '*'){
            dp[0][j] = dp[0][j - 1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }else if(pattern[j - 1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }else{
                dp[i][j] = false;
            }
        }
    }

    if(dp[n][m]){
        printf("YES");
    }else{
        printf("NO");
    }
}