#include <stdio.h>

int findingNumber(int A[], int n, int x){
    int count = 1;
    int first = A[0];
    for(int i = 1; i < n; i++){
        if(A[i] - first >= x){
            count++;
            first = A[i];
        }
    }
    return count;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int low = 0, high = A[n - 1] - A[0];
    int ans = 0;
    while(low <= high){
        int mid = (low + high) / 2;

        if(findingNumber(A, n, mid) >= k){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    printf("%d", ans);
}