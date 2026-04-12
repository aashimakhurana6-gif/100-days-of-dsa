//Implement a hash table using quadratic probing with formula: h(k, i) = (h(k) + i*i) % m
#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];
int size;

// Initialize hash table
void init() {
    for (int i = 0; i < size; i++) {
        table[i] = -1; // -1 means empty
    }
}

// Insert using quadratic probing
void insert(int key) {
    int h = key % size;

    for (int i = 0; i < size; i++) {
        int index = (h + i * i) % size;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }
    printf("Hash Table Full\n");
}

// Search using quadratic probing
int search(int key) {
    int h = key % size;

    for (int i = 0; i < size; i++) {
        int index = (h + i * i) % size;

        if (table[index] == key)
            return 1;

        if (table[index] == -1)
            return 0; // stop if empty slot found
    }
    return 0;
}

int main() {
    int q;
    scanf("%d", &size);
    scanf("%d", &q);

    init();

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}