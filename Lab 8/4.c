#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct HeapNode{
    int sum;
    int a;
    int b;
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
    while(index > 0 && heap->arr[parent(index)].sum > heap->arr[index].sum){
        struct HeapNode temp = heap->arr[parent(index)];
        heap->arr[parent(index)] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent(index);
    }
}

void heapifyDown(struct MinHeap *heap, int index){
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if(left < heap->size && heap->arr[left].sum < heap->arr[smallest].sum){
        smallest = left;
    }
    if(right < heap->size && heap->arr[right].sum < heap->arr[smallest].sum){
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
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int A[n1], B[n2];
    for(int i = 0; i < n1; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < n2; i++){
        scanf("%d", &B[i]);
    }

    int k;
    scanf("%d", &k);

    struct MinHeap heap;
    initHeap(&heap);

    int x = MIN(n1, k);

    for(int i = 0; i < x; i++){
        struct HeapNode node;
        node.sum = A[i] + B[0];
        node.a = i;
        node.b = 0;

        insert(&heap, node);
    }

    struct HeapNode curr;
    for(int i = 0; i < k; i++){
        curr = delete(&heap);

        int a = curr.a;
        int b = curr.b;

        if(b + 1 < n2){
            struct HeapNode node;
            node.sum = B[b + 1] + A[a];
            node.a = a;
            node.b = b + 1;

            insert(&heap, node);
        }

        printf("%d %d\n", A[a], B[b]);
    } 
}