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

int traversal(struct Node* root){
    if(root == NULL){
        return 0;
    }

    return root->data + traversal(root->left) + traversal(root->right);
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
    int x;
    scanf("%d", &x);

    struct Node* mover = search(root, x);

    printf("%d", traversal(mover));
}