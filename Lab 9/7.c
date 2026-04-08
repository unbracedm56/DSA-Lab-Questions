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

int traversal(struct Node* root, int* count, int k){
    if(root == NULL){
        return -1;
    }

    int left = traversal(root->left, count, k);
    if(left != -1) return left;

    (*count)++;
    if(*count == k) return root->data;

    return traversal(root->right, count, k);
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

    int k;
    scanf("%d", &k);

    int count = 0;
    printf("%d", traversal(root, &count, k));

}