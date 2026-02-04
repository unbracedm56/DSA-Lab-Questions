#include <stdio.h>

typedef struct{
    int value;
    int index;
} Node;

void merge(Node A[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Node L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2){
        if (L[i].value <= R[j].value)
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
}

void merge_sort(Node A[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    Node A[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i].value);
        A[i].index = i;
    }

    merge_sort(A, 0, n - 1);

    int i = 0;
    while (i < n){
        int j = i;
        int minIdx = A[i].index;
        int maxIdx = A[i].index;

        while (j < n && A[j].value == A[i].value){
            if (A[j].index < minIdx)
                minIdx = A[j].index;
            if (A[j].index > maxIdx)
                maxIdx = A[j].index;
            j++;
        }

        if (maxIdx - minIdx > k){
            printf("%d %d", minIdx, maxIdx);
            return 0;
        }

        i = j;
    }

    printf("-1");
    return 0;
}