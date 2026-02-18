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
    int days[n];

    push(&st, 0);
    for(int i = 1; i < n; i++){
        while(top(&st) != -1 && A[i] > A[top(&st)]){
            days[top(&st)] = i - top(&st);
            pop(&st);
        }
        push(&st, i);
    }

    while(top(&st) != -1){
        days[top(&st)] = 0;
        pop(&st);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", days[i]);
    }
}