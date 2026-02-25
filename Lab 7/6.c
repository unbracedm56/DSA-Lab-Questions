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

int peek(struct Queue *q){
    if(q->end < q->front){
        return -1;
    }

    return q->arr[q->front];
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int A[n];
    struct Queue q;
    initQueue(&q);

    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        enqueue(&q, i);
    }

    int time = 0;

    while(A[k] != 0){
        int i = dequeue(&q);

        A[i]--;
        time++;

        if(A[i] > 0){
            enqueue(&q, i);
        }
    }

    printf("%d", time);
}