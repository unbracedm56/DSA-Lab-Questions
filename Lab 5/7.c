#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

int quickSelect(int arr[], int low, int high, int k){
    if(low <= high){
        int p = partition(arr, low, high);

        if(p == k){
            return arr[p];
        }else if(p < k){
            return quickSelect(arr, p + 1, high, k);
        }else{
            return quickSelect(arr, low, p - 1, k);
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    int k;
    scanf("%d", &k);

    k = n - k;

    printf("%d", quickSelect(A, 0, n - 1, k));

}