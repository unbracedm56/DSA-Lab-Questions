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
    int found = -1;
    while(low <= high){
        int mid = (low + high)/2;

        if(A[mid] == target){
            found = mid;
            break;
        }else if (A[low] <= A[mid]){
            if (A[low] <= target && target <= A[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else if (A[mid] <= A[high]){
            if (A[mid] <= target && target <= A[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    printf("%d", found);

}