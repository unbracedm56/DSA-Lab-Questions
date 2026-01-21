#include <stdio.h>

// int main(){
//     int size_A;
//     scanf("%d", &size_A);
//     int A[size_A];
//     for(int i = 0; i<size_A; i++){
//         scanf("%d", &A[i]);
//     }

//     int size_B;
//     scanf("%d", &size_B);
//     int B[size_B];
//     for (int i = 0; i < size_B; i++){
//         scanf("%d", &B[i]);
//     }

//     int C[size_A + size_B];
//     int a = 0, b = 0;
//     for(int i = 0; i<size_A+size_B; i++){
//         if(A[a] <= B[b]){
//             C[i] = A[a];
//             a++;
//         }else if(A[a] > B[b]){
//             C[i] = B[b];
//             b++;
//         }
//     }
//     for(int i = 0; i<size_A+size_B; i++){
//         printf("%d ", C[i]);
//     }
// }

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

    int C[size_A + size_B];
    int i = 0, a = 0, b = 0;
    while((a < size_A) && (b < size_B)){
        if (A[a] <= B[b]){
            C[i++] = A[a++];
        }else if(A[a] > B[b]){
            C[i++] = B[b++];
        }
    }

    if(a >= size_A){
        while(b < size_B){
            C[i++] = B[b++];
        }
    }
    if(b >= size_B){
        while(a < size_A){
            C[i++] = A[a++];
        }
    }

    for (int i = 0; i < size_A + size_B; i++){
        printf("%d ", C[i]);
    }
}