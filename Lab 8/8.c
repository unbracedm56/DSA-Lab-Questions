#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct HeapNode{
    int h;
    int r;
    int c;
};

struct MinHeap{
    struct HeapNode arr[100];
    int size;
};

void initHeap(struct MinHeap *heap){
    heap->size = 0;
}

int parent(int i){
    return (i - 1)/2;
}

int leftChild(int i){
    return 2*i + 1;
}

int rightChild(int i){
    return 2*i + 2;
}

void heapifyUp(struct MinHeap *heap, int index){
    while(index > 0 && heap->arr[parent(index)].h > heap->arr[index].h){
        struct HeapNode temp = (heap->arr[parent(index)]);
        heap->arr[parent(index)] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent(index);
    }
}

void heapifyDown(struct MinHeap *heap, int index){
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if(left < heap->size && heap->arr[left].h < heap->arr[smallest].h){
        smallest = left;
    }
    if(right < heap->size && heap->arr[right].h < heap->arr[smallest].h){
        smallest = right;
    }

    if(smallest != index){
        struct HeapNode temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        heapifyDown(heap, smallest);
    }
}

void insert(struct MinHeap *heap, struct HeapNode x){
    heap->arr[heap->size] = x;
    heapifyUp(heap, heap->size);
    heap->size++;
}

struct HeapNode peek(struct MinHeap *heap){
    return heap->arr[0];
}

struct HeapNode delete(struct MinHeap *heap){
    struct HeapNode maxValue = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return maxValue;
}

int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];
    int visited[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &matrix[i][j]);
            visited[r][c] = 0;
        }
    }

    struct MinHeap heap;
    initHeap(&heap);

    for(int i = 0; i < r; i++){
        struct HeapNode c1;
        c1.r = i;
        c1.c = 0;
        c1.h = matrix[i][0];
        insert(&heap, c1);
        visited[i][0] = 1;

        if(c - 1 > 0){
            struct HeapNode c2;
            c2.r = i;
            c2.c = c - 1;
            c2.h = matrix[i][c - 1];
            insert(&heap, c2);
            visited[i][c - 1] = 1;
        }
    }
    for(int i = 0; i < c; i++){
        struct HeapNode r1;
        r1.r = 0;
        r1.c = i;
        r1.h = matrix[0][i];
        insert(&heap, r1);
        visited[0][i] = 1;

        if(r - 1 > 0){
            struct HeapNode r2;
            r2.r = r - 1;
            r2.c = i;
            r2.h = matrix[r - 1][i];
            insert(&heap, r2);
            visited[r - 1][i] = 1;
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int water = 0;
    while (heap.size > 0) {
        struct HeapNode curr = delete(&heap);

        for (int d = 0; d < 4; d++) {
            int nx = curr.r + dx[d];
            int ny = curr.c + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) {
                continue;
            }

            visited[nx][ny] = 1;

            if (matrix[nx][ny] < curr.h) {
                water += curr.h - matrix[nx][ny];
            }

            struct HeapNode next;
            next.h = MAX(matrix[nx][ny], curr.h);
            next.r = nx;
            next.c = ny;

            insert(&heap, next);
        }
    }

    printf("%d", water);
}