#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int left = 0, maxSize = 2;
    int maxLeft = 0, maxRight = 1;
    int k = A[1] - A[0];

    for(int right = 1; right < n; right++){
        if(A[right] - A[right - 1] == k){
            if(right - left + 1 > maxSize){
                maxSize = right - left + 1;
                maxLeft = left;
                maxRight = right;
            }
        }else{
            k = A[right] - A[right - 1];
            left = right - 1;
        }
    }

    printf("%d %d", maxLeft + 1, maxRight + 1);
}