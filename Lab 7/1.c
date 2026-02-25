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

int isEmpty(struct Stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
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

struct Queue{
    struct Stack s1;
    struct Stack s2;
};

void initQueue(struct Queue *q){
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(struct Queue *q, int x){
    push(&q->s1, x);
}

int dequeue(struct Queue *q){
    if(isEmpty(&q->s1) == 1 && isEmpty(&q->s2) == 1){
        return -1;
    }
    if(isEmpty(&q->s2) == 1){
        while(isEmpty(&q->s1) == 0){
            push(&q->s2, top(&q->s1));
            pop(&q->s1);
        }
    }

    int x = top(&q->s2);
    pop(&q->s2);
    return x;
}

int peek(struct Queue *q){
    if(isEmpty(&q->s1) == 1 && isEmpty(&q->s2) == 1){
        return -1;
    }
    if(isEmpty(&q->s2) == 1){
        while(isEmpty(&q->s1) == 0){
            push(&q->s2, top(&q->s1));
            pop(&q->s1);
        }
    }

    return top(&q->s2);
}

int main(){
    int t;
    scanf("%d", &t);
    int A[t][2];
    for(int i = 0; i < t; i++){
        scanf("%d", &A[i][0]);
        if(A[i][0] == 1){
            scanf("%d", &A[i][1]);
        }
    }

    struct Queue q;
    initQueue(&q);

    for(int i = 0; i < t; i++){
        if(A[i][0] == 1){
            enqueue(&q, A[i][1]);
        }else if(A[i][0] == 2){
            printf("%d\n", dequeue(&q));
        }else if(A[i][0] == 3){
            printf("%d\n", peek(&q));
        }
    }
}