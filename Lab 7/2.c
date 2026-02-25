#include <stdio.h>
#include <string.h>

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
    char str[100];
    fgets(str, sizeof(str), stdin);

    int freq[1000] = {0};
    struct Queue q;
    initQueue(&q);
    
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '\n'){
            return 0;
        }
        freq[str[i] - 'a']++;
        enqueue(&q, i);

        while(peek(&q) != -1 && freq[str[peek(&q)] - 'a'] > 1){
            dequeue(&q);
        }


        if(peek(&q) == -1){
            printf("-1 ");
        }else{
            printf("%c ", str[peek(&q)]);
        }
            
    }
}