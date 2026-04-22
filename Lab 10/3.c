#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Insert or update
void insert(Node* table[], int m, int key, int value) {
    int idx = key % m;

    Node* curr = table[idx];

    // If chain is empty → insert directly
    if (curr == NULL) {
        table[idx] = createNode(key, value);
        return;
    }

    Node* prev = NULL;

    // Traverse to find key or reach end
    while (curr != NULL) {
        if (curr->key == key) {
            curr->value += value;  // update
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // Not found → insert at tail
    prev->next = createNode(key, value);
}

// Print table
void printTable(Node* table[], int m) {
    for (int i = 0; i < m; i++) {
        Node* curr = table[i];

        if (curr == NULL) {
            printf("Empty\n");
        } else {
            while (curr != NULL) {
                printf("[%d:%d]", curr->key, curr->value);
                if (curr->next != NULL) printf("->");
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

int main() {
    int m, q;
    scanf("%d %d", &m, &q);

    Node* table[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = NULL;
    }

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int key, value;
            scanf("%d %d", &key, &value);
            insert(table, m, key, value);
        }
        else if (type == 2) {
            printTable(table, m);
        }
    }

    return 0;
}