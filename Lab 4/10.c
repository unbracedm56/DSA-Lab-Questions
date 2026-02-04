#include <stdio.h>

int taxCap(int A[], int n, int c){
    int revenue = 0;
    for(int i = 0; i<n; i++){
        if(A[i] <= c){
            revenue += A[i];
        }else{
            revenue += c;
        }
    }
    return revenue;
}

int main(){
    int n, g;
    scanf("%d %d", &n, &g);
    int A[n];
    int maxIncome = 0, sum = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
        if(maxIncome < A[i]){
            maxIncome = A[i];
        }
        sum += A[i];
    }
    if(sum < g){
        printf("-1");
        return 0;
    }

    int low = 0, high = maxIncome;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;

        if(taxCap(A, n, mid) >= g){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    printf("%d", ans);
}