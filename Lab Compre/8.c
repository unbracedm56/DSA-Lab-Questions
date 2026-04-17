#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(){
    int n;
    scanf("%d", &n);

    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int inc[n], dec[n];

    for(int i = 0; i < n; i++){
        inc[i] = 1;
        dec[i] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[j] < A[i]){
                inc[i] = MAX(inc[i], inc[j] + 1);
            }
        }
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j > i; j--){
            if(A[j] < A[i]){
                dec[i] = MAX(dec[i], dec[j] + 1);
            }
        }
    }

    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = inc[i] + dec[i] - 1;
    }

    int a = dp[0];
    for(int i = 0; i < n; i++){
        if(dp[i] > a){
            a = dp[i];
        }
    }

    printf("%d", a);
}