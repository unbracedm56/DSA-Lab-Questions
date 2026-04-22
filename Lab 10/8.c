#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftPart[n1], rightPart[n2];
    for(int i = 0; i < n1; i++){
        leftPart[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        rightPart[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(leftPart[i] <= rightPart[j]){
            arr[k++] = leftPart[i++];
        }else{
            arr[k++] = rightPart[j++];
        }
    }

    while(i < n1){
        arr[k++] = leftPart[i++];
    }
    while(j < n2){
        arr[k++] = rightPart[j++];
    }
}

int solve(int arr[], int left, int right){
    int count = 0;
    if(left >= right){
        return 0;
    }

    int mid = (left + right) / 2;
    count += solve(arr, left, mid);
    count += solve(arr, mid + 1, right);

    int j = mid + 1;
    for(int i = left; i <= mid; i++){
        while(j <= right && arr[i] > 2 * arr[j]){
            j++;
        }

        count += (j - (mid + 1));
    }

    merge(arr, left, mid, right);

    return count;
}

int main(){
    int n;
    scanf("%d", &n);

    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    printf("%d", solve(A, 0, n - 1));
}