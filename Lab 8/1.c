#include <stdio.h>

struct MinHeap{
    int arr[100];
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
    while(index > 0 && heap->arr[parent(index)] > heap->arr[index]){
        int temp = heap->arr[parent(index)];
        heap->arr[parent(index)] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent(index);
    }
}

void heapifyDown(struct MinHeap *heap, int index){
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if(left < heap->size && heap->arr[left] < heap->arr[smallest]){
        smallest = left;
    }
    if(right < heap->size && heap->arr[right] < heap->arr[smallest]){
        smallest = right;
    }

    if(smallest != index){
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        heapifyDown(heap, smallest);
    }
}

void insert(struct MinHeap *heap, int x){
    heap->arr[heap->size] = x;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int peek(struct MinHeap *heap){
    return heap->arr[0];
}

int delete(struct MinHeap *heap){
    int maxValue = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return maxValue;
}

int main(){
    int k, n;
    scanf("%d %d", &k, &n);

    struct MinHeap heap;
    initHeap(&heap);

    int x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);

        if(heap.size < k){
            insert(&heap, x);
        }else if(x > peek(&heap)){
            delete(&heap);
            insert(&heap, x);
        }

        if(heap.size < k){
            printf("-1 ");
        }else{
            printf("%d ", peek(&heap));
        }
    }
}