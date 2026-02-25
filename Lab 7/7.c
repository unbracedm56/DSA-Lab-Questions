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
    int n;
    scanf("%d", &n);

    int gas[n], dist[n];
    struct Queue q;
    initQueue(&q);

    for(int i = 0; i < n; i++){
        scanf("%d", &gas[i]);
        enqueue(&q, i);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &dist[i]);
    }

    
    int found = 0;
    for(int i = 0; i < n; i++){

        for(int k = 0; k < n; k++){
            enqueue(&q, (i + k) % n);
        }

        int gasLeft = 0;
        int count = 0;

        while(count < n){
            int j = dequeue(&q);
            gasLeft += (gas[j] - dist[j]);
            enqueue(&q, j);

            if(gasLeft < 0){
                break;
            }
            count++;
        }

        if(count == n && gasLeft >= 0){
            printf("%d", i);
            found = 1;
            break;
        }
        enqueue(&q, dequeue(&q));
    }

    if(found == 0){
        printf("-1");
    }
}