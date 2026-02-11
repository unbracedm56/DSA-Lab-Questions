#include <stdio.h>

int divisors(int x){
    int count = 0;
    for(int i = 1; i <= x; i++){
        if(x % i == 0){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i< n - 1; i++){
        for(int j = 0; j< n - i - 1; j++){
            int a = divisors(A[j]);
            int b = divisors(A[j + 1]);
            if(a > b){
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }else if(a == b && A[j] < A[j + 1]){
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
}