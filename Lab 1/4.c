#include <stdio.h>

void findUnion(int A[], int size_A, int B[], int size_B){
    int found;
    for(int i = 0; i<size_A; i++){
        printf("%d ", A[i]);
    }
    for (int i = 0; i < size_B; i++){
        found = 0;
        for(int j = 0; j< size_A; j++){
            if(A[j] == B[i]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            printf("%d ", B[i]);
        }
    }
}

void findIntersection(int A[], int size_A, int B[], int size_B){
    for(int i = 0; i<size_A; i++){
        for(int j = 0; j<size_B; j++){
            if(A[i] == B[j]){
                printf("%d ", A[i]);
            }
        }
    }
}

int main(){
    int size_A;
    scanf("%d", &size_A);
    int A[size_A];
    for(int i = 0; i<size_A; i++){
        scanf("%d", &A[i]);
    }

    int size_B;
    scanf("%d", &size_B);
    int B[size_B];
    for (int i = 0; i < size_B; i++){
        scanf("%d", &B[i]);
    }

    printf("Union: ");
    findUnion(A, size_A, B, size_B);
    printf("\nIntersection: ");
    findIntersection(A, size_A, B, size_B);
}