#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int freq;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->freq = 1;
    newNode->next = NULL;
    return newNode;
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    Node* table[m];
    for (int i = 0; i < m; i++) {
        table[i] = NULL;
    }
    
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        int idx = k % m;
        Node* curr = table[idx];
        Node* prev = NULL;

        while (curr != NULL) {
            if (curr->key == k) {
                curr->freq++;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            Node* newNode = createNode(k);

            if (prev == NULL) {
                table[idx] = newNode;
            } else {
                prev->next = newNode;
            }
        }
    }

    int maxFreq = 0;
    int element = -1;

    for (int i = 0; i < m; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            if (curr->freq > maxFreq ||
               (curr->freq == maxFreq && curr->key < element)) {
                maxFreq = curr->freq;
                element = curr->key;
            }
            curr = curr->next;
        }
    }

    for (int i = 0; i < m; i++) {
        Node* curr = table[i];

        printf("Index %d: ", i);

        if (curr == NULL) {
            printf("Empty\n");
        } else {
            while (curr != NULL) {
                printf("[%d:%d]", curr->key, curr->freq);
                if (curr->next != NULL) printf("->");
                curr = curr->next;
            }
            printf("\n");
        }
    }

    printf("%d %d\n", element, maxFreq);
}