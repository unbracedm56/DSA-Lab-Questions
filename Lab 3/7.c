#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    int low = 0, grpSize = 1;
    while(low < n){
        int end = low + grpSize;
        if(end > n){
            end = n;
        }

        for(int i = low; i<end - 1; i++){
            for(int j = low; j<end - 1 - (i - low); j++){
                if(A[j] > A[j+1]){
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                }
            }
        }

        low = end;
        grpSize++;
    }

    for(int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
}