// Implement Stack using Linked List
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

int push(int value);
int pop(void);
int peek(void);
void display(void);
int getvalue(void);

int main(void){
    int keepRunning = 1, choice = 0;
    char options[5][10] = {{"push"}, {"pop"}, {"peek"}, {"display"}, {"exit"}};
    for (int i = 0; i < 5; i++){
        printf("%d: %s\n", i + 1, options[i]);
    }

    while (keepRunning){
        display();
        printf("choice: ");
        if (scanf("%d", &choice) != 1){
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }
        switch (choice){
            case 1: // push
                push(getvalue());
                break;

            case 2: // pop
                printf("removed %d\n", pop());
                break;

            case 3: // peek
                printf("on top: %d\n", peek());
                break;

            case 4: // display
                display();
                break;

            case 5: // exit
                printf("Exiting...\n");
                keepRunning = 0;
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

int push(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Stack Overflow\n");
        return 1;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    return 0;
}

int pop(void){
    if (top == NULL){
        printf("Stack Underflow\n");
        return 0;
    }
    struct node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int peek(void){
    if (top == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display(void){
    if (top == NULL){
        printf("stack: []\n");
        return;
    }
    printf("stack: [");
    struct node* temp = top;
    while (temp){
        printf("%d", temp->data);
        if (temp->next != NULL){
            printf(",");
        }
        temp = temp->next;
    }
    printf("]\n");
}

int getvalue(void){
    int value;
    printf("value: ");
    scanf("%i", &value);
    return value;
}