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

    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* temp = NULL;
    while(curr != NULL && curr->next != NULL){
        struct Node* nextNext = curr->next->next;
        struct Node* second = curr->next;
        second->next = curr;
        curr->next = nextNext;

        if(prev == NULL){
            head = second;
        }else{
            prev->next = second;
        }
        
        prev = curr;
        curr = nextNext;
    }

    mover = head;
    while(mover != NULL){
        printf("%d ", mover->data);
        mover = mover->next;
    }
}