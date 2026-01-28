#include <stdio.h>

struct Student{
    int marks;
    int delay;
};

int main(){
    int n;
    scanf("%d", &n);
    struct Student A[n];
    for(int i = 0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        A[i].marks = a;
        A[i].delay = b;
    }

    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(A[j].marks > A[j+1].marks){
                struct Student temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }else if(A[j].marks == A[j+1].marks){
                if(A[j].delay < A[j+1].delay){
                    struct Student temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        printf("%d %d\n", A[i].marks, A[i].delay);
    }

}