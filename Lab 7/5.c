#include <stdio.h>

struct Deque{
    int arr[100];
    int front;
    int end;
};

void initDeque(struct Deque * dq){
    dq->front = 0;
    dq->end = -1;
}

int isEmpty(struct Deque *dq){
    return dq->front > dq->end;
}

void pushBack(struct Deque *dq, int x){
    dq->arr[++(dq->end)] = x;
}

void popBack(struct Deque *dq){
    dq->end--;
}

void popFront(struct Deque *dq){
    dq->front++;
}

int getFront(struct Deque *dq){
    return dq->arr[dq->front];
}

int getBack(struct Deque *dq){
    return dq->arr[dq->end];
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    struct Deque dq;
    initDeque(&dq);

    int ans[n];
    int idx = 0;

    for(int i = 0; i < n; i++){
        while(!isEmpty(&dq) && getFront(&dq) < i - k + 1){
            popFront(&dq);
        }

        while(!isEmpty(&dq) && A[getBack(&dq)] < A[i]){
            popBack(&dq);
        }

        pushBack(&dq, i);

        if(i >= k - 1){
            ans[idx++] = A[getFront(&dq)];
        }
    }

    for(int i = 0; i < idx; i++){
        printf("%d ", ans[i]);
    }
}