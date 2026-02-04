#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }

    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;

        if(A[mid]-mid-1 >= k){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    printf("%d", low+k);
}