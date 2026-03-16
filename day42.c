//Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, i, x;

    scanf("%d", &n);

    // Input and enqueue
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue elements to stack
    for(i = 0; i < n; i++) {
        push(dequeue());
    }

    // Move back from stack to queue
    front = 0;
    rear = -1;
    for(i = 0; i < n; i++) {
        enqueue(pop());
    }

    // Print reversed queue
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}