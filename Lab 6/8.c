#include <stdio.h>

struct Stack{
    int arr[100];
    int top;
};

void initStack(struct Stack *s){
    s->top = -1;
}

void push(struct Stack *s, int x){
    if(s->top >= 99){
        return;
    }
    s->top++;
    s->arr[s->top] = x;
}

int top(struct Stack *s){
    if(s->top == -1){
        return -1;
    }
    return s->arr[s->top];
}

void pop(struct Stack *s){
    if(s->top == -1){
        return;
    }
    s->top--;
}

int size(struct Stack *s){
    return s->top + 1;
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    int target[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &target[i]);
    }

    struct Stack st;
    initStack(&st);

    int j = 0;

    int B[2*n];
    int k = 0;

    for(int i = 0; i < n; i++){
        push(&st, A[i]);
        B[k++] = 1;

        while(size(&st) > 0 && j < n && target[j] == top(&st)){
            pop(&st);
            j++;
            B[k++] = 2;
        }
    }

    if(size(&st) != 0 || j != n){
        printf("Impossible");
    }else{
        for(int i = 0; i < k; i++){
            if(B[i] == 1){
                printf("Push\n");
            }else if(B[i] == 2){
                printf("Pop\n");
            }
        }
    }
}