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
    int k;
    scanf("%d", &k);

    int nums[100][100];
    int size[100];

    for(int i = 0; i < k; i++){
        scanf("%d", &size[i]);
        for(int j = 0; j < size[i]; j++){
            scanf("%d", &nums[i][j]);
        }
    }

    struct MinHeap heap;
    initHeap(&heap);

    int currentMax = 0;
    for(int i = 0; i < k; i++){
        struct HeapNode node;
        node.value = nums[i][0];
        node.r = i;
        node.c = 0;
        insert(&heap, node);

        if(nums[i][0] > currentMax){
            currentMax = nums[i][0];
        }
    }

    int bestStart = peek(&heap).value;
    int bestEnd = currentMax;

    while (1) {
        struct HeapNode curr = delete(&heap);
        int currentMin = curr.value;

        // Update best range
        if ((currentMax - currentMin < bestEnd - bestStart) ||
            (currentMax - currentMin == bestEnd - bestStart && currentMin < bestStart)) {
            bestStart = currentMin;
            bestEnd = currentMax;
        }

        int r = curr.r;
        int c = curr.c;

        // If this list is exhausted, stop
        if (c + 1 >= size[r]) {
            break;
        }

        // Insert next element from same list
        struct HeapNode nextNode;
        nextNode.value = nums[r][c + 1];
        nextNode.r = r;
        nextNode.c = c + 1;
        insert(&heap, nextNode);

        if (nextNode.value > currentMax) {
            currentMax = nextNode.value;
        }
    }

    printf("%d %d", bestStart, bestEnd);
}