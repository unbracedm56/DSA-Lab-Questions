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

void peek(struct Stack *s){
    if(s->top == -1){
        printf("Stack Empty\n");
        return;
    }
    printf("Top: %d\n", s->arr[s->top]);
}

void pop(struct Stack *s){
    if(s->top == -1){
        printf("Stack Empty\n");
        return;
    }
    printf("Popped: %d\n", s->arr[s->top]);
    s->top--;
}

void getMin(struct Stack *s){
    if(s->top == -1){
        printf("Stack Empty\n");
        return;
    }
    int min = s->arr[0];
    for(int i = 0; i <= s->top; i++){
        if(s->arr[i] < min){
            min = s->arr[i];
        }
    }
    printf("Minimum: %d\n", min);
}

int main(){
    int n;
    scanf("%d", &n);
    struct Stack st;
    initStack(&st);
    int operations[n][2];

    for(int i = 0; i < n; i++){
        scanf("%d", &operations[i][0]);
        if(operations[i][0] == 1){
            scanf("%d", &operations[i][1]);
        }else{
            operations[i][1] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        int a = operations[i][0];
        if(a == 1){
            int x = operations[i][1];
            push(&st, x);
        }else if(a == 2){
            pop(&st);
        }else if(a == 3){
            getMin(&st);
        }else if(a == 4){
            peek(&st);
        }
    }
}