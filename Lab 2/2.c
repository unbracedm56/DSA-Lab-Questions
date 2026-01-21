#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n;
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *mover = NULL;

    for (int i = 0; i < n; i++){
        int a;
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &a);
        temp->data = a;
        temp->next = NULL;

        if (head == NULL){
            head = temp;
            mover = temp;
        }else{
            mover->next = temp;
            mover = mover->next;
        }
    }

    struct Node* evenHead = NULL, *evenTail = NULL;
    struct Node* oddHead = NULL, *oddTail = NULL;
    struct Node *curr = head;

    while(curr != NULL){
        struct Node* nextNode = curr->next;
        curr->next = NULL;

        if(curr->data %2 == 0){
            if(evenHead == NULL){
                evenHead = evenTail = curr;
            }else{
                evenTail->next = curr;
                evenTail = curr;
            }
        }else{
            if(oddHead == NULL){
                oddHead = oddTail = curr;
            }else{
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = nextNode;
    }

    if(evenHead != NULL){
        head = evenHead;
        evenTail->next = oddHead;
    }else{
        head = oddHead;
    }

    mover = head;
    while(mover != NULL){
        printf("%d ", mover->data);
        mover = mover->next;
    }
}