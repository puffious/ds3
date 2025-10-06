// Write a program to convert an infix expression to postfix using a stack.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char value){
    if (top >= MAX-1){
        printf("Stack overflow\n");
        return;
    }
    else {
        stack[++top] = value;
        printf("pushed: %c\n", value);
    }
}

char pop(){
    if (top >= 0) {
        printf("POPS: %c\n", stack[top]);
        return stack[top--];
    }
    else return '\0';
}

char peep(){
    if (top >= 0) {
        return stack[top];
    }
    else return '\0';
}

void display(){
    printf("stack: [");
    for (int i = 0; i <= top; i++){
        printf("%c", stack[i]);
        if (i != top){
            printf(",");
        }
    }
    printf("]\n");
}

int getPrecendence(char operator){
    switch (operator){
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

int main(void){
    int temp = 0;
    char infix[MAX];
    char topEntity;
    char postfix[MAX];

    printf("enter infix expression: ");
    fgets(infix, MAX, stdin);
    
    // Remove newline from fgets
    infix[strcspn(infix, "\n")] = '\0';

    for (int i = 0; infix[i] != '\0'; i++){
        char current = infix[i];
        int currentPrecendence = getPrecendence(current);
        
        // check if operand
        if (currentPrecendence == 0 && current != '(' && current != ')') {
            postfix[temp++] = current;
        }

        // push if '('
        else if (current == '('){
            push(current);
        }

        else if (current == ')'){
            while ((topEntity = pop()) != '(' && topEntity != '\0'){
                postfix[temp++] = topEntity;
            }
        }
        
        // operator
        else if (currentPrecendence > 0) {
            while (top != -1 && peep() != '(' && getPrecendence(peep()) >= currentPrecendence){
                postfix[temp++] = pop();
            }
            push(current);
        }
    }
    
    while (top != -1){
        postfix[temp++] = pop();
    }
    
    postfix[temp] = '\0';  // Null-terminate the string
    printf("%s\n", postfix);
}
