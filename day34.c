//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct Node *temp;
    int x;

    temp = top;
    x = temp->data;
    top = top->next;

    free(temp);
    return x;
}

int evaluate(char *exp)
{
    int i=0, op1, op2;

    while(exp[i] != '\0')
    {
        if(exp[i] == ' ')
        {
            i++;
            continue;
        }

        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(exp[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }

    return pop();
}

int main()
{
    char postfix[100];

    printf("Enter postfix expression: ");
    gets(postfix);

    int result = evaluate(postfix);

    printf("Result = %d", result);

    return 0;
}