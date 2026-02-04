#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    int startFront = 0, grpSize = 1, startBack = n;
    while(startFront < startBack){
        if(grpSize % 2 != 0){
            int endFront = startFront + grpSize;
            if(endFront > startBack){
                endFront = startBack;
            }
            for(int i = startFront; i<endFront-1; i++){
                for(int j = startFront; j<endFront-1-(i-startFront); j++){
                    if(A[j] > A[j+1]){
                        int temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                    }
                }
            }
            startFront = endFront;
            grpSize++;
        }else{
            int endBack = startBack;
            startBack -= grpSize;
            if(startBack < startFront){
                startBack = startFront;
            }
            for(int i = startBack; i<endBack-1; i++){
                for(int j = startBack; j<endBack-1-(i-startBack); j++){
                    if(A[j] > A[j+1]){
                        int temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                    }
                }
            }

            grpSize++;
        }
    }

    for(int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
}