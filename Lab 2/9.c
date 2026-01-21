#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
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

    int count_even = 0, count_odd = 0;
    for(int i = 0; i<n; i++){
        if(i % 2 == 0){
            if(A[i] % 2 == 0){
                count_even++;
            }
        }else{
            if(A[i] % 2 != 0){
                count_odd++;
            }
        }
    }

    printf("%d, %d", count_even, count_odd);
}