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

    struct Stack st;
    initStack(&st);

    int left[n], right[n];

    for(int i = 0; i < n; i++){
        while(size(&st) > 0 && A[top(&st)] > A[i]){
            pop(&st);
        }

        if(size(&st) == 0){
            left[i] = i + 1;
        }else{
            left[i] = i - top(&st);
        }

        push(&st, i);
    }

    initStack(&st);

    for(int i = n - 1; i >= 0; i--){
        while(size(&st) > 0 && A[top(&st)] >= A[i]){
            pop(&st);
        }

        if(size(&st) == 0){
            right[i] = n - i;
        }else{
            right[i] = top(&st) - i;
        }

        push(&st, i);
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += (A[i] * left[i] * right[i]);
    }

    printf("%d", sum);
}