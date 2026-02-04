#include <stdio.h>

int strength(int num){
    int count = 0;
    while(num > 0){
        count += num % 2;
        num/=2;
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            int strength1 = strength(A[j]), strength2 = strength(A[j+1]);
            if(strength1 < strength2){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }else if (strength1 == strength2){
                if(A[j] < A[j+1]){
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
}