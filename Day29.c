// Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, i, value, k;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    if (n == 0) {
        printf("List is empty");
        return 0;
    }

    // Create first node
    scanf("%d", &value);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;
    temp = head;

    // Create remaining nodes
    for (i = 1; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    scanf("%d", &k);

    // Step 1: Find length
    int count = 1;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Step 2: Reduce k
    k = k % count;

    if (k == 0) {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Step 3: Make circular
    temp->next = head;

    // Step 4: Move to (count - k)th node
    int steps = count - k;
    struct Node *ptr = head;

    for (i = 1; i < steps; i++) {
        ptr = ptr->next;
    }

    // Step 5: Break circle
    head = ptr->next;
    ptr->next = NULL;

    // Step 6: Print rotated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}