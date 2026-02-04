#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int k;
    scanf("%d", &k);

    int row = 0, col = m-1;
    while(row < n && col >= 0){

        if(matrix[row][col] == k){
            printf("%d %d", row, col);
            return 0;
        }else if(matrix[row][col] < k){
            row++;
        }else{
            col--;
        }
    }

    printf("-1");
    return 0;
}