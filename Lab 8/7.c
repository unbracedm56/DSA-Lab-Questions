#include <stdio.h>

struct MaxHeap{
    int arr[100];
    int size;
};

struct CoolDown{
    int count;
    int timeDown;
};

void initHeap(struct MaxHeap *heap){
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

void heapifyUp(struct MaxHeap *heap, int index){
    while(index > 0 && heap->arr[parent(index)] < heap->arr[index]){
        int temp = heap->arr[parent(index)];
        heap->arr[parent(index)] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent(index);
    }
}

void heapifyDown(struct MaxHeap *heap, int index){
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if(left < heap->size && heap->arr[left] > heap->arr[largest]){
        largest = left;
    }
    if(right < heap->size && heap->arr[right] > heap->arr[largest]){
        largest = right;
    }

    if(largest != index){
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;
        heapifyDown(heap, largest);
    }
}

void insert(struct MaxHeap *heap, int x){
    heap->arr[heap->size] = x;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int peek(struct MaxHeap *heap){
    return heap->arr[0];
}

int delete(struct MaxHeap *heap){
    int maxValue = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return maxValue;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int freq[26] = {0};
    for(int i = 0; i < n; i++){
        char a;
        scanf(" %c", &a);
        freq[a - 'A']++;
    }

    struct MaxHeap heap;
    initHeap(&heap);

    struct CoolDown q[1000];
    int front = 0, rear = 0;

    for(int i = 0; i < 26; i++){
        if (freq[i] > 0){
            insert(&heap, freq[i]);
        }
    }

    int time = 0;
    while(heap.size > 0 || front < rear){
        while(front < rear && q[front].timeDown <= time){
            insert(&heap, q[front].count);
            front++;
        }

        if(heap.size > 0){
            int cnt = delete(&heap);
            cnt--;

            if(cnt > 0){
                q[rear].count = cnt;
                q[rear].timeDown = time + k + 1;
                rear++;
            }
        }

        time++;
    }

    printf("%d", time);
}