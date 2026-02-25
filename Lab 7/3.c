#include <stdio.h>

struct Queue{
    int arr[100];
    int front;
    int end;
};

void initQueue(struct Queue *q){
    q->front = 0;
    q->end = -1;
}

void enqueue(struct Queue *q, int x){
    if(q->end >= 99){
        return;
    }
    q->end++;
    q->arr[q->end] = x;
}

int dequeue(struct Queue *q){
    if(q->end < q->front){
        return -1;
    }

    int x = q->arr[q->front];
    q->front++;
    return x;
}

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

int peek(struct Queue *q){
    if(q->end < q->front){
        return -1;
    }

    return q->arr[q->front];
}

int main(){
    int n;
    scanf("%d", &n);

    struct Queue q;
    initQueue(&q);

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        enqueue(&q, a);
    }

    struct Stack st;
    initStack(&st);

    for(int i = 0; i < n / 2; i++){
        push(&st, dequeue(&q));
    }
    
    while(isEmpty(&st) == 0){
        enqueue(&q, top(&st));
        pop(&st);
    }

    for(int i = 0; i < n / 2; i++){
        enqueue(&q, dequeue(&q));
    }

    for(int i = 0; i < n / 2; i++){
        push(&st, dequeue(&q));
    }

    while(isEmpty(&st) == 0){
        enqueue(&q, top(&st));
        pop(&st);
        enqueue(&q, dequeue(&q));
    }

    for(int i = 0; i < n; i++){
        printf("%d ", dequeue(&q));
    }
}