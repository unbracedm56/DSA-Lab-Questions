#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    int n;
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *mover = NULL;
    for (int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a;
        temp->next = NULL;

        if (head == NULL){
            head = mover = temp;
        }else{
            mover->next = temp;
            mover = temp;
        }
    }
    
    int x;
    scanf("%d", &x);

    struct Node* headX = NULL, *tailX = NULL;
    struct Node* curr = head;
    struct Node* prev = NULL;

    while(curr != NULL){
        if(curr->data == x){
            struct Node* currX = curr;
            if(prev == NULL){
                head = curr->next;
            }else{
                prev->next = curr->next;
            }
            curr = curr->next;
            currX->next = NULL;
            if(headX == NULL){
                headX = tailX = currX;
            }else{
                tailX->next = currX;
                tailX = currX;
            }
        }else{
            prev = curr;
            curr = curr->next;
        }
    }

    if(head == NULL){
        head = headX;
    }else{
        prev->next = headX;
    }

    mover = head;
    while(mover != NULL){
        printf("%d ", mover->data);
        mover = mover->next;
    }
}