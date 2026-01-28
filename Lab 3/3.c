#include <stdio.h>

int possibleX(int X, int pile[], int n, int h){
    int hours = 0;
    for(int i = 0; i<n; i++){
        hours += (pile[i] + X - 1)/X;
        if(hours > h) return 0;
    }

    return 1;
}

int main(){
    int n, h;
    scanf("%d %d", &n, &h);
    int pile[n];
    int maxPile = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &pile[i]);
        if(pile[i] > maxPile){
            maxPile = pile[i];
        }
    }

    int low = 1, high = maxPile;
    int ans = maxPile;
    while(low <= high){
        int mid = (low + high)/2;

        if(possibleX(mid, pile, n, h)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }

    }

    printf("%d", ans);
}