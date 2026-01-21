#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    int B[n+2];
    for(int i = 0; i<n+2; i++){
        scanf("%d", &B[i]);
    }

    int a = 0;
    for(int i = 0; i<n+2; i++){
        int found = 0;
        for(int j = 0; j<n; j++){
            if(B[i] == A[j]){
                found = 1;
                A[j] = -1;
                break;
            }
        }
        if(found == 0){
            printf("%d ", B[i]);
            a++;
        }
        if(a == 2){
            return 0;
        }
    }
}