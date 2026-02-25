//Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
struct Node* deleteFirst(struct Node* head, int key) {
    struct Node *curr = head, *prev = NULL;

    // Case 1: If head node holds the key
    if (curr != NULL && curr->data == key) {
        head = curr->next;
        free(curr);
        return head;
    }

    // Search for the key
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If key not found
    if (curr == NULL)
        return head;

    // Remove node
    prev->next = curr->next;
    free(curr);

    return head;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, value, key;
    struct Node* head = NULL;

    // Input size
    scanf("%d", &n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Input key
    scanf("%d", &key);

    // Delete first occurrence
    head = deleteFirst(head, key);

    // Output result
    printList(head);

    return 0;
}