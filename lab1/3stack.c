// Implement a stack using arrays and perform the following operations: Push, Pop, Peep, and Display.

#include <stdio.h>


int top = 0;
int stack[10];

void push(int value);
int pop();
void display();
int peep();

int main(void) {
    int keepRunning = 1, choice = 0, temp = 0;
    char options[5][10] = {{"push"}, {"pop"}, {"peep"}, {"display"}, {"exit"}};
    for (int i = 0; i < 5; i++) {
        printf("%d: %s\n", i + 1, options[i]);
    }

    while (keepRunning) {
        display();
        printf("choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1: // push
                printf("value: ");
                scanf("%d", &temp);
                push(temp);
                break;

            case 2: // pop
                printf("removed %d\n", pop());
                break;

            case 3: // peep
                printf("on top: %d\n", peep());
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

void push(int value){
    stack[top] = value;
    top ++;
}

int pop(){
    if (top > 0) {
        top --;
        return stack[top];
    }
    else return 0;
}

int peep(){
    return stack[top-1];
}

void display(){
    printf("stack: [");
    for (int i = 0; i < top; i++){
        printf("%d", stack[i]);
        if (i != top-1){
            printf(",");
        }
    }
    printf("]\n");
}
