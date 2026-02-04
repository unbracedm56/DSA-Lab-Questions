#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n][2];
    for(int i = 0; i<n; i++){
        scanf("%d %d", &A[i][0], &A[i][1]);
    }

    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(A[j][0] > A[j+1][0]){
                int temp1 = A[j][0], temp2 = A[j][1];
                A[j][0] = A[j+1][0];
                A[j][1] = A[j+1][1];
                A[j+1][0] = temp1;
                A[j+1][1] = temp2;
            }else if (A[j][0] == A[j + 1][0]){
                if (A[j][1] > A[j + 1][1]){
                    int temp1 = A[j][0], temp2 = A[j][1];
                    A[j][0] = A[j + 1][0];
                    A[j][1] = A[j + 1][1];
                    A[j + 1][0] = temp1;
                    A[j + 1][1] = temp2;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        printf("%d %d\n", A[i][0], A[i][1]);
    }

    int maxReach = A[0][1];
    int fragmented = 0;

    for(int i = 1; i<n; i++){
        if(A[i][0] > maxReach){
            fragmented = 1;
            break;
        }
        if(A[i][1] > maxReach){
            maxReach = A[i][1];
        }
    }

    if(fragmented == 1){
        printf("Fragmented");
    }else{
        printf("Contiguous");
    }
}