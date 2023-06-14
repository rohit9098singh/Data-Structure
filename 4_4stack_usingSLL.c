#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;
stack *top;

int stackEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
void push()
{
    stack *p;
    if (top == NULL)
    {
        top = (stack *)malloc(sizeof(stack));
        printf("Enter the data");
        scanf("%d", &top->data);
        top->next = NULL;
    }
    else
    {
        p = (stack *)malloc(sizeof(stack));
        printf("Enter the data");
        scanf("%d", &p->data);
        p->next = top;
        top = p;
    }
}
void pop()
{
    int i;
    stack *p;
    i = stackEmpty();
    if (i == 0)
    {
        p = top;
        top = top->next;
        printf("Deleted element is %d", p->data);
        free(p);
    }
    else
    {
        printf("stack is empty");
    }
}
void display()
{
    stack *p;
    p = top;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

void main()
{
    int choice;
    top = NULL;
    while (1)
    {
        printf("Enter your choice\n 1.Push \n 2.pop \n 3.display \n 4.exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
        case 4:
            exit(1);
            break;
        }
    }
}