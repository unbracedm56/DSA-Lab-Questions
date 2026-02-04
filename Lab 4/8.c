#include <stdio.h>

int painter(int A[], int n, int k, int x){
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++){
        if (A[i] > x){
            return 0;
        }
        if (sum + A[i] <= x){
            sum += A[i];
        }else{
            painters++;
            sum = A[i];
        }
    }

    return painters <= k;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int A[n];
    int maxNum = 0, sum = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
        if(A[i] > maxNum){
            maxNum = A[i];
        }
        sum += A[i];
    }

    int low = maxNum, high = sum;
    int ans = sum;
    while(low <= high){
        int mid = (low+high)/2;

        if (canPaint(A, n, k, mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    printf("%d", ans);
}