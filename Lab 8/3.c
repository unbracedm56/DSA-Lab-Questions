#include <stdio.h>

struct Heap{
    int arr[100];
    int size;
};

void initHeap(struct Heap *heap){
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

void heapifyUpMin(struct Heap *heap, int index){
    while(index > 0 && heap->arr[parent(index)] > heap->arr[index]){
        int temp = heap->arr[parent(index)];
        heap->arr[parent(index)] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent(index);
    }
}

void heapifyDownMin(struct Heap *heap, int index){
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
        heapifyDownMin(heap, smallest);
    }
}

void insertMin(struct Heap *heap, int x){
    heap->arr[heap->size] = x;
    heapifyUpMin(heap, heap->size);
    heap->size++;
}

int peek(struct Heap *heap){
    return heap->arr[0];
}

int deleteMin(struct Heap *heap){
    int maxValue = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDownMin(heap, 0);
    return maxValue;
}

void heapifyUpMax(struct Heap *heap, int index){
    while(index > 0 && heap->arr[parent(index)] < heap->arr[index]){
        int temp = heap->arr[parent(index)];
        heap->arr[parent(index)] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent(index);
    }
}

void heapifyDownMax(struct Heap *heap, int index){
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap->size && heap->arr[left] > heap->arr[largest]){
        largest = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[largest]){
        largest = right;
    }

    if (largest != index){
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;
        heapifyDownMax(heap, largest);
    }
}

void insertMax(struct Heap *heap, int x){
    heap->arr[heap->size] = x;
    heapifyUpMax(heap, heap->size);
    heap->size++;
}

int deleteMax(struct Heap *heap){
    int maxValue = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDownMax(heap, 0);
    return maxValue;
}

int main(){
    int n;
    scanf("%d", &n);

    struct Heap minHeap;
    struct Heap maxHeap;
    initHeap(&minHeap);
    initHeap(&maxHeap);

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        
        if(maxHeap.size == 0 || peek(&maxHeap) >= x){
            insertMax(&maxHeap, x);
        }else{
            insertMin(&minHeap, x);
        }

        if(maxHeap.size - minHeap.size > 1){
            insertMin(&minHeap, deleteMax(&maxHeap));
        }
        else if (minHeap.size - maxHeap.size > 1){
            insertMax(&maxHeap, deleteMin(&minHeap));
        }

        if(maxHeap.size == minHeap.size){
            int a = peek(&maxHeap);
            int b = peek(&minHeap);
            printf("%.1f ", (a+b)/2.0);
        }
        else if (maxHeap.size > minHeap.size){
            printf("%.1f ", (float)peek(&maxHeap));
        }else{
            printf("%.1f ", (float)peek(&minHeap));
        }
    }
}