#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    int total_xor = A[0];
    for(int i = 1; i<n; i++){
        total_xor ^= A[i];
    }

    for(int i = 2; i<n-1; i++){
        if(A[i] == total_xor){
            printf("%d ", i+1);
        }
    }
}