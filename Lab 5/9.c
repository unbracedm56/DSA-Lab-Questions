#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(A[j] > A[j + 1]){
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    int found = 0;
    for(int i = 0; i < n; i++){
        if(i > 0 && A[i] == A[i - 1]) continue;
        
        int low = i + 1, high = n - 1;
        while(low < high){
            int sum = A[i] + A[low] + A[high];
            if(sum == 0){
                printf("%d %d %d\n", A[i], A[low], A[high]);
                found++;

                while(low < high && A[low] == A[low + 1]) low++;
                while (low < high && A[high] == A[high - 1]) high--;

                low++;
                high--;
            }else if(sum < 0){
                low++;
            }else{
                high--;
            }
        }
    }
    if(found == 0){
        printf("No triplets found");
    }
}