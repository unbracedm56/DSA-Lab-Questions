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

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while(front < rear){
        int levelSize = rear - front;
        int arr[levelSize];

        for(int i = 0; i < levelSize; i++){
            struct Node* curr = queue[front++];
            arr[i] = curr->data;

            if(curr->left != NULL){
                queue[rear++] = curr->left;
            }
            if(curr->right != NULL){
                queue[rear++] = curr->right;
            }
        }

        if(leftToRight == 1){
            for(int i = 0; i < levelSize; i++){
                printf("%d ", arr[i]);
            }
            leftToRight = 0;
        }else{
            for(int i = levelSize - 1; i >= 0; i--){
                printf("%d ", arr[i]);
            }
            leftToRight = 1;
        }
    }
}