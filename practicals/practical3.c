#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
void peep();

int top = 0;
int stack[10];
int MAX = 10;

int main()
{
    int choice;
    printf(" Jwalin Patel \n 225BECEG014 \n");
    while (1)
    {
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Peep");
        printf("\n 4. Display");
        printf("\n 5. Exit");
        printf("\n Enter your choice: ");
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
            peep();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("\n Enter valid choice: ");
        }
    }
    return 0;
}
void push()
{
    int value;
    if (top >= MAX)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);
        stack[top] = value;
        top++;
        printf("Pushed %d onto the stack.\n", value);
    }
}

void pop()
{
    if (top > 0)
    {
        top--;
        printf("Popped %d from the stack.\n", stack[top]);
    }
    else
    {
        printf("Stack Underflow! Nothing to pop.\n");
    }
}

void peep()
{
    if (top > 0)
    {
        printf("Top element: %d\n", stack[top - 1]);
    }
    else
    {
        printf("Stack is empty.\n");
    }
}

void display()
{
    if (top == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom):\n");
    for (int i = top - 1; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
