#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int temp;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    int curr = arr[0], count = 0;
    for(int i = 0; i<n; i++){
        if(curr == arr[i]){
            count++;
        }else{
            printf("%d -> %d\n", curr, count);
            count = 1;
            curr = arr[i];
        }
    }
    printf("%d -> %d\n", curr, count);
}