#include <stdio.h>

struct Node{
    int r;
    int c;
    int dist;
};

struct Queue{
    struct Node arr[100];
    int front;
    int end;
};

void initQueue(struct Queue *q){
    q->front = 0;
    q->end = -1;
}

void enqueue(struct Queue *q, struct Node x){
    if(q->end >= 99){
        return;
    }
    q->end++;
    q->arr[q->end] = x;
}

struct Node dequeue(struct Queue *q){
    struct Node x = q->arr[q->front];
    q->front++;
    return x;
}

int isEmpty(struct Queue *q){
    return q->front > q->end;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    int matrix[n][m];
    int visited[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
            visited[i][j] = 0;
        }
    }

    struct Queue q;
    initQueue(&q);

    struct Node start = {0, 0, 1};
    enqueue(&q, start);
    visited[0][0] = 1;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while(!isEmpty(&q)){
        struct Node curr = dequeue(&q);

        int r = curr.r;
        int c = curr.c;
        int dist = curr.dist;

        if(matrix[r][c] == 2){
            printf("%d", dist);
            return 0;
        }

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] != 1 && visited[nr][nc] == 0){
                visited[nr][nc] = 1;

                struct Node next = {nr, nc, dist + 1};

                enqueue(&q, next);
            }
        }
    }
}