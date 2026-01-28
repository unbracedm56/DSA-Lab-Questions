#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }
    int target;
    scanf("%d", &target);

    int low = 0, high = n-1;
    int first = -1, last = -1;

    while(low <= high){
        int mid = (low + high)/2;

        if(A[mid] == target){
            first = mid;
            high = mid - 1;
        }else if(A[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;

        if(A[mid] == target){
            last = mid;
            low = mid + 1;
        }else if(A[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    printf("%d %d", first, last);
}