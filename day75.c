//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

#include <stdio.h>
#include <stdlib.h>

// Structure for hash map
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define SIZE 1000

Node* hashTable[SIZE];

// Hash function
int hash(int key) {
    return abs(key) % SIZE;
}

// Insert into hash map
void insert(int key, int value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search in hash map
int search(int key) {
    int index = hash(key);
    Node* temp = hashTable[index];
    
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1;
}

int maxLenZeroSum(int arr[], int n) {
    int prefix_sum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Case 1: sum = 0
        if (prefix_sum == 0)
            max_len = i + 1;

        // Case 2: sum seen before
        int prev_index = search(prefix_sum);

        if (prev_index != -1) {
            int len = i - prev_index;
            if (len > max_len)
                max_len = len;
        } else {
            insert(prefix_sum, i);
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLenZeroSum(arr, n));

    return 0;
}