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

int size(struct Queue *q){
    if(q->end < q->front){
        return 0;
    }
    return q->end - q->front + 1;
}

int main(){
    int n;
    scanf("%d", &n);

    int time[n], direc[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &time[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &direc[i]);
    }

    struct Queue entering;
    struct Queue exiting;
    initQueue(&entering);
    initQueue(&exiting);

    int timeCurr = 0;
    int momentum = 0;
    int nextPerson = 0;
    int processed = 0;
    int ans[n];

    while(processed < n){
        while(nextPerson < n && time[nextPerson] == timeCurr){
            if(direc[nextPerson] == 0){
                enqueue(&entering, nextPerson);
            }else{
                enqueue(&exiting, nextPerson);
            }
            nextPerson++;
        }

        int used = 0;

        if(size(&entering) == 0 && size(&exiting) == 0){
            momentum = 0;
        }else if(size(&entering) == 0){
            int i = dequeue(&exiting);
            ans[i] = timeCurr;
            momentum = -1;
            used = 1;
        }else if(size(&exiting) == 0){
            int i = dequeue(&entering);
            ans[i] = timeCurr;
            momentum = 1;
            used = 1;
        }else{
            if(momentum == -1 || momentum == 0){
                int i = dequeue(&exiting);
                ans[i] = timeCurr;
                momentum = -1;
            }else{
                int i = dequeue(&entering);
                ans[i] = timeCurr;
                momentum = 1;
            }
            used = 1;
        }

        if(used){
            processed++;
        }

        timeCurr++;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }
}