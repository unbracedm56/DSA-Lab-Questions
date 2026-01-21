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
    struct Node *mover = NULL;
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

    mover = head;
    int i = 0, sum = 0;
    // struct Node* prev = NULL;
    while(mover != NULL){
        if(i < 2){
            sum += mover->data;
            i++;
        }
        if(i == 2 || mover->next == NULL){
            struct Node* sum_temp = (struct Node*)malloc(sizeof(struct Node));
            sum_temp->data = sum;
            sum_temp->next = mover->next;
            mover->next = sum_temp;
            if(mover->next != NULL){
                mover = mover->next;
            }
            sum = 0;
            i = 0;
        }

        // prev = mover;
        mover = mover->next;
    }

    mover = head;
    while(mover != NULL){
        printf("%d ", mover->data);
        mover = mover->next;
    }
}