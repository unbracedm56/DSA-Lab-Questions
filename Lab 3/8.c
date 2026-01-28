#include <stdio.h>

int shipping(int weights[], int n, int d, int capacity){
    int days = 0;
    int sum = 0;

    for(int i = 0; i<n; i++){
        if(weights[i] > capacity) return 0;
        sum += weights[i];
        if(sum == capacity){
            days++;
            sum = 0;
        }else if (sum > capacity){
            days++;
            sum = weights[i];
        }
    }

    if(sum != 0){
        days++;
    }

    if(days <= d){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n, d;
    scanf("%d %d", &n, &d);
    int weights[n];
    int sum = 0, maxWeight = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &weights[i]);
        sum += weights[i];
        if(weights[i] > maxWeight){
            maxWeight = weights[i];
        }
    }

    int low = maxWeight, high = sum;
    int ans = sum;
    while(low <= high){
        int mid = (low + high)/2;

        if(shipping(weights, n, d, mid) == 1){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    printf("%d", ans);
}