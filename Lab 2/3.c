#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* mover = NULL;

    for(int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = a;
        temp->next = NULL;

        if(head == NULL){
            head = mover = temp;
        }else{
            mover->next = temp;
            mover = temp;
        }
    }

    int k;
    scanf("%d", &k);
    k = k % n;
    int steps = n-k;

    struct Node* curr = head;
    struct Node* prev = NULL;
    while(curr != NULL && steps>0){
        prev = curr;
        curr = curr->next;
        steps--;
    }

    mover->next = head;
    head = curr;
    prev->next = NULL;

    mover = head;
    while(mover != NULL){
        printf("%d ", mover->data);
        mover = mover->next;
    }
}