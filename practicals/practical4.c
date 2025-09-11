// Infix to Postfix Conversion
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
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

char pop()
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

char peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    else
    {
        return '\0';
    }
}

int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char character, top_operator;

    for (i = 0; infix[i] != '\0'; i++)
    {
        character = infix[i];

        // If operand, add to postfix
        if (isalnum(character))
        {
            postfix[j++] = character;
        }
        // If '(', push to stack
        else if (character == '(')
        {
            push(character);
        }
        // If ')', pop until '('
        else if (character == ')')
        {
            while ((top_operator = pop()) != '(' && top_operator != '\0')
            {
                postfix[j++] = top_operator;
            }
        }
        // If operator
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(character))
            {
                postfix[j++] = pop();
            }
            push(character);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    //     For each character c in the infix expression:
    //     If c is an operand:
    //         Append c to the postfix expression
    //     Else if c is '(':
    //         Push '(' onto the stack
    //     Else if c is ')':
    //         While the top of the stack is not '(':
    //             Pop from the stack and append to the postfix expression
    //         Pop the '(' from the stack (but do not append)
    //     Else if c is an operator:
    //         While the stack is not empty AND the top of the stack has
    //               an operator with higher or equal precedence than c:
    //             Pop from the stack and append to the postfix expression
    //         Push the current operator c onto the stack

    // After processing all characters in the infix expression:
    //     While the stack is not empty:
    //         Pop from the stack and append to the postfix expression
}

int main()
{
    printf("Name: Tirth Rana 225BECEG002 \n");
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: \n");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression is: %s\n", postfix);

    return 0;
}
