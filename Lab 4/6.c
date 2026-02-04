#include <stdio.h>
#include <limits.h>

int counting(int r, int c, int matrix[r][c], int x){
    int count = 0;
    for(int i = 0; i<r; i++){
        int low = 0, high = c-1;
        while(low <= high){
            int mid = (low + high)/2;

            if(matrix[i][mid] <= x){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        count += low;
    }

    return count;
}

int main(){
    int r, c;
    scanf("%d %d", &r, &c);
    int matrix[r][c];
    int minNum = INT_MAX, maxNum = INT_MIN;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] > maxNum){
                maxNum = matrix[i][j];
            }
            if (matrix[i][j] < minNum){
                minNum = matrix[i][j];
            }
        }
    }

    int low = minNum, high = maxNum;
    int number = (r * c)/2;
    while(low <= high){
        int mid = (low + high)/2;

        if(counting(r, c, matrix, mid) <= number){
            low = mid + 1;
        }else{
            high = mid - 1;
        }

    }

    printf("%d", low);
}