#include <stdio.h>
#include <stdlib.h>

int* rotateLeft(int arr[], int n, int k){
    int* arr_new = (int*)malloc(n * sizeof(int));

    int i = 0;
    for(int j = k; j<n; j++){
        arr_new[i++] = arr[j];
    }
    for(int j = 0; j<k; j++){
        arr_new[i++] = arr[j];
    }

    return arr_new;
}

int* rotateRight(int arr[], int n, int k){
    int *arr_new = (int *)malloc(n * sizeof(int));

    int i = 0;
    for(int j=n-k; j<n; j++){
        arr_new[i++] = arr[j];
    }
    for(int j = 0; j<n-k; j++){
        arr_new[i++] = arr[j];
    }

    return arr_new;
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int shift;
    scanf("%d", &shift);
    int k;
    scanf("%d", &k);

    if(shift == 0){
        printArray(rotateLeft(arr, n, k), n);
    }else{
        printArray(rotateRight(arr, n, k), n);
    }
}