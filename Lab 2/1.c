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
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &a);
        temp->data = a;
        temp->next = NULL;
        
        if(head == NULL){
            head = temp;
            mover = temp;
        }else{
            mover->next = temp;
            mover = mover->next;
        }
    }

    mover = head;
    for(int i = 0; i<n/2; i++){
        mover = mover->next;
    }

    struct Node* headReverse = NULL;
    while(mover != NULL){
        struct Node* temp = mover;
        mover = mover->next;

        if(headReverse == NULL){
            headReverse = temp;
            headReverse->next = NULL;
        }else{
            temp->next = headReverse;
            headReverse = temp;
        }
    }

    int palindrome = 1;
    struct Node* moverReverse = headReverse;
    mover = head;
    while(mover != NULL && moverReverse != NULL){
        if(mover->data == moverReverse->data){
            mover = mover->next;
            moverReverse = moverReverse->next;
        }else{
            palindrome = 0;
            break;
        }
    }

    if(palindrome == 1){
        printf("True");
    }else{
        printf("False");
    }


}