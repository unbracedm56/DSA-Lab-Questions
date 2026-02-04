#include <stdio.h>

int main(){
    int k;
    scanf("%d", &k);

    int low = 0, high = 1000;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;

        if(mid*mid <= k){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    printf("%d", ans);
}