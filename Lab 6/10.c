#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct MultiNode{
    int data;
    struct Node* side;
    struct MultiNode* down;
};

int main(){
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    struct MultiNode* head = NULL;
    struct MultiNode *moverDown = NULL;

    for(int i = 0; i < n; i++){
        struct Node *headSide = NULL;
        struct Node* moverSide = NULL;
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1){
                struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
                temp->data = j;
                temp->next = NULL;
                if(headSide == NULL){
                    headSide = moverSide = temp;
                }else{
                    moverSide->next = temp;
                    moverSide = temp;
                }
            }
        }

        struct MultiNode* temp1 = (struct MultiNode*)malloc(sizeof(struct MultiNode));
        temp1->data = i;
        temp1->side = headSide;
        temp1->down = NULL;

        if(head == NULL){
            head = moverDown = temp1;
        }else{
            moverDown->down = temp1;
            moverDown = temp1;
        }
    }

    moverDown = head;
    while(moverDown != NULL){
        struct Node* mover = moverDown->side;
        printf("%d -> ", moverDown->data);
        while(mover != NULL){
            printf("%d", mover->data);
            if(mover->next != NULL){
                printf(" -> ");
            }
            mover = mover->next;
        }
        if(moverDown->down != NULL){
            printf("\n|\n");
        }

        moverDown = moverDown->down;
    }
}