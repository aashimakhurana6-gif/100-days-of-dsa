//Deque (Double-Ended Queue)
#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front==-1)
        front = rear = 0;
    else if(front==0)
        front = MAX-1;
    else
        front--;

    deque[front] = x;
}

void push_back(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front==-1)
        front = rear = 0;
    else if(rear==MAX-1)
        rear = 0;
    else
        rear++;

    deque[rear] = x;
}

void pop_front()
{
    if(front==-1)
    {
        printf("Deque Underflow\n");
        return;
    }

    if(front==rear)
        front = rear = -1;
    else if(front==MAX-1)
        front = 0;
    else
        front++;
}

void pop_back()
{
    if(front==-1)
    {
        printf("Deque Underflow\n");
        return;
    }

    if(front==rear)
        front = rear = -1;
    else if(rear==0)
        rear = MAX-1;
    else
        rear--;
}

int get_front()
{
    if(front==-1)
        return -1;
    return deque[front];
}

int get_back()
{
    if(front==-1)
        return -1;
    return deque[rear];
}

int size()
{
    if(front==-1)
        return 0;

    if(rear>=front)
        return rear-front+1;

    return MAX-front+rear+1;
}

void display()
{
    int i;

    if(front==-1)
    {
        printf("Deque Empty\n");
        return;
    }

    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d ",deque[i]);
    }
    else
    {
        for(i=front;i<MAX;i++)
            printf("%d ",deque[i]);

        for(i=0;i<=rear;i++)
            printf("%d ",deque[i]);
    }
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    printf("Deque elements: ");
    display();

    return 0;
}