// Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial node
struct Node {
    int coef;
    int exp;
    struct Node *next;
};

int main() {
    int n, i;

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;

    scanf("%d", &n);

    if (n == 0) {
        printf("Polynomial is empty");
        return 0;
    }

    // Create polynomial linked list
    for (i = 0; i < n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d %d", &newNode->coef, &newNode->exp);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Print Polynomial
    temp = head;

    while (temp != NULL) {

        if (temp->exp > 1)
            printf("%dx^%d", temp->coef, temp->exp);
        else if (temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%d", temp->coef);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}