#include <stdio.h>

int main(){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i<n-1; i++){
        int swap = 0;
        for(int j = 0; j<n-i-1; j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swap = 1;
            }
        }
        if(swap == 0){
            break;
        }
    }

    int left = 0;
    int maxCount = 0;

    for(int right = 0; right < n; right++){
        while(A[right] - A[left] > k){
            left++;
        }

        int windowSize = right - left + 1;
        if(windowSize > maxCount){
            maxCount = windowSize;
        }
    }

    printf("%d", maxCount);
}