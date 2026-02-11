#include <stdio.h>

void rotateLayer(int n, int m, int a[n][m], int top, int bottom, int left, int right, int clockwise){
    int temp[400];
    int k = 0;

    for(int i = left; i <= right; i++){
        temp[k++] = a[top][i];
    }
    for(int i = top + 1; i <= bottom; i++){
        temp[k++] = a[i][right];
    }
    for(int j = right - 1; j >= left; j--){
        temp[k++] = a[bottom][j];
    }
    for(int i = bottom - 1; i > top; i--){
        temp[k++] = a[i][left];
    }

    if(clockwise){
        int last = temp[k - 1];
        for(int i = k - 1; i > 0; i--){
            temp[i] = temp[i - 1];
        }
        temp[0] = last;
    }else{
        int first = temp[0];
        for(int i = 0; i < k - 1; i++){
            temp[i] = temp[i + 1];
        }
        temp[k - 1] = first;
    }

    int idx = 0;
    for(int i = left; i <= right; i++){
        a[top][i] = temp[idx++];
    }
    for(int i = top + 1; i <= bottom; i++){
        a[i][right] = temp[idx++];
    }
    for(int j = right - 1; j >= left; j--){
        a[bottom][j] = temp[idx++];
    }
    for(int i = bottom - 1; i > top; i--){
        a[i][left] = temp[idx++];
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int layers = (n < m ? n : m) / 2;

    for(int i = 0; i < layers; i++){
        int top = i, left = i;
        int bottom = n - i - 1, right = m - i - 1;

        if(top == bottom || left == right) continue;

        int clockwise = (i % 2 == 0);
        rotateLayer(n, m, matrix, top, bottom, left, right, clockwise);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}