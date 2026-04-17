#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(){
    int n, h;
    scanf("%d %d", &n, &h);

    int hours[n], payments[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &payments[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &hours[i]);
    }

    int dp[n + 1][h + 1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= h; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i - 1][j];

                if(hours[i - 1] <= j){
                    dp[i][j] = MAX(dp[i][j], payments[i - 1] + dp[i - 1][j - hours[i - 1]]);
                }
            }
        }
    }

    printf("%d", dp[n][h]);
}