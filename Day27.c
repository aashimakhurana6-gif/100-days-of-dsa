// Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node *next;
};

// Function to create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to find length
int getLength(struct Node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
int findIntersection(struct Node *head1, struct Node *head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff;

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    if(len1 > len2) {
        diff = len1 - len2;
        while(diff--)
            ptr1 = ptr1->next;
    } else {
        diff = len2 - len1;
        while(diff--)
            ptr2 = ptr2->next;
    }

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main() {
    int n, m, i, value;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL;

    // First List Creation
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if(head1 == NULL)
            head1 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    // Second List Creation
    temp = NULL;
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if(head2 == NULL)
            head2 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    int result = findIntersection(head1, head2);

    if(result != -1)
        printf("%d", result);
    else
        printf("No Intersection");

    return 0;
}