//Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front==-1)
    {
        front = rear = 0;
    }
    else if(rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = x;
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;

    if(front==-1)
    {
        printf("Queue Empty");
        return;
    }

    if(front <= rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for(i=front;i<MAX;i++)
            printf("%d ", queue[i]);

        for(i=0;i<=rear;i++)
            printf("%d ", queue[i]);
    }
}

int main()
{
    int n,m,i,x;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    scanf("%d",&m);

    for(i=0;i<m;i++)
        dequeue();

    display();

    return 0;
}