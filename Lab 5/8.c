#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int interval[n][2];
    for(int i = 0; i<n; i++){
        scanf("%d %d", &interval[i][0], &interval[i][1]);
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(interval[j][0] > interval[j + 1][0]){
                int temp1 = interval[j][0], temp2 = interval[j][1];
                interval[j][0] = interval[j + 1][0];
                interval[j][1] = interval[j + 1][1];
                interval[j + 1][0] = temp1;
                interval[j + 1][1] = temp2;
            }
        }
    }

    int start = interval[0][0], end = interval[0][1];
    for(int i = 1; i<n; i++){
        if(interval[i][0] <= end){
            if(interval[i][1] > end){
                end = interval[i][1];
            }
        }else{
            printf("%d %d\n", start, end);
            start = interval[i][0];
            end = interval[i][1];
        }
    }
    printf("%d %d", start, end);
}