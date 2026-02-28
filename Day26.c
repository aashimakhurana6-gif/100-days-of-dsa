//Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp, *newNode;

    // Input number of nodes
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        // If list is empty
        if(head == NULL) {
            head = newNode;
        }
        else {
            temp = head;

            // Move to last node
            while(temp->next != NULL) {
                temp = temp->next;
            }

            // Insert at end
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Forward Traversal
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}