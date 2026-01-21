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

    struct Node* curr = head;
    while(curr != NULL && curr->next != NULL){
        struct Node* nextNode = curr->next;
        if(nextNode->data <= curr->data){
            curr->next = nextNode->next;
            free(nextNode);
        }else{
            curr = curr->next;
        }
    }

    mover = head;
    while(mover != NULL){
        printf("%d ", mover->data);
        if(mover->next != NULL){
            printf("-> ");
        }
        mover = mover->next;
    }
}