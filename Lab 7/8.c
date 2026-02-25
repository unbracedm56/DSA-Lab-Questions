#include <stdio.h>
#include <string.h>

struct Queue{
    char arr[100][100];
    int front;
    int end;
};

void initQueue(struct Queue *q){
    q->front = 0;
    q->end = -1;
}

void enqueue(struct Queue *q, char x[]){
    if(q->end >= 99){
        return;
    }
    q->end++;
    strcpy(q->arr[q->end], x);
}

void dequeue(struct Queue *q, char x[]){
    if(q->end < q->front){
        x[0] = '\0';
        return;
    }

    strcpy(x, q->arr[q->front]);
    q->front++;
}

void peek(struct Queue *q, char x[]){
    if(q->end < q->front){
        return;
    }

    strcpy(x, q->arr[q->front]);
}

int main(){
    int n;
    scanf("%d", &n);

    struct Queue q;
    initQueue(&q);

    enqueue(&q, "1");

    for(int i = 0; i < n; i++){
        char a[100];
        dequeue(&q, a);

        printf("%s  ", a);

        char next0[100], next1[100];
        strcpy(next0, a);
        strcpy(next1, a);

        strcat(next0, "0");
        strcat(next1, "1");

        enqueue(&q, next0);
        enqueue(&q, next1);
    }
}