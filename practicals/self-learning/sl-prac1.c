// evaluate postfix using stack

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int c)
{
    if (top < MAX - 1)
    {
        stack[++top] = c;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

int pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        return '\0';
    }
}

int performOperation(int op1, int op2, char opr)
{
    switch (opr)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2; // assume no division by zero
    case '^':
        return (int)pow(op1, op2);
    default:
        printf("Invalid operator: %c\n", opr);
        return 0;
    }
}

int evaluatePostfix(char postfix[])
{
    int i, j = 0;
    char temp;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        temp = postfix[i];

        // If digit then push to stack
        if (isdigit(temp))
        {
            push(temp - '0');
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            int value = performOperation(op1, op2, temp);
            push(value);
        }
    }
    return pop();
}
int main()
{
    char postfix[MAX];

    printf("Name: Tirth Rana 225BECEG002 \n");
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("\nEvaluated postfix expression is : %d", result);
}