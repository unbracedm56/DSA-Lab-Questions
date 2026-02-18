#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Stack{
    double arr[100];
    int top;
};

void initStack(struct Stack *s){
    s->top = -1;
}

void push(struct Stack *s, double x){
    if(s->top >= 99) return;
    s->top++;
    s->arr[s->top] = x;
}

double top(struct Stack *s){
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

    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            push(&st, (double)(str[i] - '0'));
        }else{
            double a = top(&st);
            pop(&st);
            double b = top(&st);
            pop(&st);
            if(a == -1 || b == -1){
                printf("Invalid Expression");
                return 0;
            }
            double result;
            if(str[i] == '+'){
                result = b + a;
            }else if(str[i] == '-'){
                result = b - a;
            }else if(str[i] == '*'){
                result = b * a;
            }else if(str[i] == '/'){
                if(a == 0){
                    printf("Invalid Expression");
                    return 0;
                }
                result = b / (double)a;
            }

            push(&st, result);
        }
    }

    printf("%.2f", top(&st));
}