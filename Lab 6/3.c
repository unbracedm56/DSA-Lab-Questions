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

    int maxArea = 0;
    int i = 0;

    while(i < n){
        if(size(&st) == 0 || A[i] >= A[top(&st)]){
            push(&st, i);
            i++;
        }else{
            int height = A[top(&st)];
            pop(&st);
            int width;

            if(size(&st) == 0){
                width = i;
            }else{
                width = i - top(&st) - 1;
            }

            int area = height * width;
            if(area > maxArea){
                maxArea = area;
            }
        }
    }

    while(size(&st) > 0){
        int height = A[top(&st)];
        pop(&st);
        int width;

        if(size(&st) == 0){
            width = i;
        }else{
            width = i - top(&st) - 1;
        }

        int area = height * width;
        if(area > maxArea){
            maxArea = area;
        }
    }

    printf("%d", maxArea);
}