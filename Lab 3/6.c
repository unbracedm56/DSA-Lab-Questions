#include <stdio.h>

int F(int x){
    return ((2*x*x*x) - (x*x) + (5*x));
}

int main(){
    int y;
    scanf("%d", &y);

    int low = 0, high = 80;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;

        if(F(mid) <= y){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    printf("%d", ans);
}