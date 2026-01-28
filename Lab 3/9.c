#include <stdio.h>

int merge(int A[], int left, int right, int mid){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int count = 0;

    int L[n1], R[n2];
    for(int i = 0; i<n1; i++){
        L[i] = A[left + i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = A[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            A[k++] = L[i++];
        }else{
            A[k++] = R[j++];
            count += (n1 - i);
        }
    }

    while(i < n1){
        A[k++] = L[i++];
    }
    while(j < n2){
        A[k++] = R[j++];
    }

    return count;
}

int merge_sort(int A[], int left, int right){
    int count = 0;
    if(left < right){
        int mid = (left + right)/2;

        count += merge_sort(A, left, mid);
        count += merge_sort(A, mid + 1, right);
        count += merge(A, left, right, mid);
    }

    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n], B[n];
    for(int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        A[i] = a;
        B[i] = a;
    }
    printf("%d", merge_sort(B, 0, n-1));
}