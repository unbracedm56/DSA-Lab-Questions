#include <stdio.h>

struct HeapNode{
    int value;
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
    while(index > 0 && heap->arr[parent(index)].value > heap->arr[index].value){
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

    if(left < heap->size && heap->arr[left].value < heap->arr[smallest].value){
        smallest = left;
    }
    if(right < heap->size && heap->arr[right].value < heap->arr[smallest].value){
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
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int k;
    scanf("%d", &k);

    struct MinHeap heap;
    initHeap(&heap);

    for(int i = 0; i < n; i++){
        struct HeapNode node;
        node.value = matrix[i][0];
        node.r = i;
        node.c = 0;

        insert(&heap, node);
    }

    struct HeapNode curr;

    for(int i = 0; i < k; i++){
        curr = delete(&heap);

        int r = curr.r;
        int c = curr.c;

        if(c+1 < n){
            struct HeapNode node;
            node.value = matrix[r][c+1];
            node.r = r;
            node.c = c + 1;
            insert(&heap, node);
        }
    }

    printf("%d", curr.value);
}