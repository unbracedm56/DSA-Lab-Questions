#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    int left = 0, right = n-1;
    while(left < right){
        int mid = (left+right)/2;
        if(A[mid] < A[mid + 1]){
            left = mid + 1;
        }else if (A[mid] >= A[mid+1]){
            right = mid;
        }
    }

    printf("%d", left);
}