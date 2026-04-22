#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Insert in sorted order into the chain
void insertSorted(Node** head, int key) {
    Node* newNode = createNode(key);

    if (*head == NULL || (*head)->key > key) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL && curr->next->key < key) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

// Search for key in sorted chain
int search(Node* head, int key) {
    Node* curr = head;

    while (curr != NULL && curr->key <= key) {
        if (curr->key == key) {
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}

int main() {
    int m, nA, nB;
    scanf("%d %d %d", &m, &nA, &nB);

    Node* table[m];
    for (int i = 0; i < m; i++) {
        table[i] = NULL;
    }

    // Read Database A and insert into hash table
    for (int i = 0; i < nA; i++) {
        int id;
        scanf("%d", &id);
        int index = id % m;
        insertSorted(&table[index], id);
    }

    int intersection[nB];
    int count = 0;

    // Read Database B and search
    for (int i = 0; i < nB; i++) {
        int id;
        scanf("%d", &id);
        int index = id % m;
        if (search(table[index], id)) {
            intersection[count++] = id;
        }
    }

    // Print result
    printf("Intersection:");
    if (count == 0) {
        printf(" None\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf(" %d", intersection[i]);
        }
        printf("\n");
    }

    return 0;
}