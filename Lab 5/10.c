#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    int maxNum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        if(A[i] > maxNum){
            maxNum = A[i];
        }
    }
    int output[n];

    for(int exp = 1; maxNum / exp > 0; exp *= 10){
        int count[10] = {0};

        for(int i = 0; i < n; i++){
            count[(A[i] / exp) % 10]++;
        }

        for(int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }

        for(int i = n - 1; i >= 0; i--){
            output[count[(A[i] / exp) % 10] - 1] = A[i];
            count[(A[i] / exp) % 10]--;
        }

        for(int i = 0; i < n; i++){
            A[i] = output[i];
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    
}