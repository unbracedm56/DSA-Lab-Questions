#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int x){
    if(root == NULL){
        return createNode(x);
    }

    if(x < root->data){
        root->left = insert(root->left, x);
    }else if(x > root->data){
        root->right = insert(root->right, x);
    }

    return root;
}

struct Node* search(struct Node* root, int x){
    if(root == NULL || root->data == x){
        return root;
    }

    if(x < root->data){
        return search(root->left, x);
    }

    return search(root->right, x);
}

int main(){
    int n;
    scanf("%d", &n);
    
    struct Node* root = NULL;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        root = insert(root, a);
    }
    int a, b;
    scanf("%d %d", &a, &b);

    struct Node* mover = root;
    while(mover != NULL){
        if(a < mover->data && b < mover->data){
            mover = mover->left;
        }else if(a > mover->data && b > mover->data){
            mover = mover->right;
        }else{
            break;
        }
    }

    struct Node* mover1 = mover;
    int countA = 0, countB = 0;
    while(mover1 != NULL){
        countA += mover1->data;
        if(a < mover1->data){
            mover1 = mover1->left;
        }else if(a > mover1->data){
            mover1 = mover1->right;
        }else{
            break;
        }
    }

    struct Node *mover2 = mover;
    while(mover2 != NULL){
        countB += mover2->data;
        if(b < mover2->data){
            mover2 = mover2->left;
        }else if(b > mover2->data){
            mover2 = mover2->right;
        }else{
            break;
        }
    }

    printf("%d", (countA + countB - mover->data));
}