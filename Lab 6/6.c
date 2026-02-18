#include <stdio.h>
#include <string.h>

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
    char str[100];
    fgets(str, sizeof(str), stdin);

    struct Stack st;
    initStack(&st);

    int maxLenght = 0;
    push(&st, -1);

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '('){
            push(&st, i);
        }else if(str[i] == ')'){
            pop(&st);

            if(size(&st) == 0){
                push(&st, i);
            }else{
                if(i - top(&st) > maxLenght){
                    maxLenght = i - top(&st);
                }
            }
        }
    }

    printf("%d", maxLenght);
}