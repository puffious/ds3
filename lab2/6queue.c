// Write a program to implement a queue using arrays and perform Enqueue, Dequeue, and Display operations.
#include <stdio.h>

int size = 10;
int queue[10];
int rear = -1;
int front = -1;

int enqueue(int value);
int dequeue(void);
int peep(void);
int getvalue(void);
void display(void);

int main(void){
    int keepRunning = 1, choice = 0, temp = 0;
    char options[5][10] = {{"enqueue"}, {"dequeue"}, {"peep"}, {"display"}, {"exit"}};
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
                enqueue(getvalue());
                break;

            case 2: // pop
                printf("removed %d\n", dequeue());
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

int enqueue(int value){
    if (rear == size-1){ // rear pointer has reached the end of queue
        printf("Queue OverFlow\n");
        return 1;
    }
    if (front == -1){
        front = 0;
    }
    rear ++; //increment rear pointer to the next "empty space"
    queue[rear] = value;
    return 0;
}

int dequeue(void){
    if (front == -1){
        printf("Queue UnderFlow\n");
        return 0;
    }

    int value = queue[front];

    if (front == rear){
        // printf("Queue Is Empty\n");
        front = -1;
        rear = -1;
    }
    else {
        front ++;
    }
    return value;
}

int peep(void){
    if (front == -1){
        printf("Queue UnderFlow\n");
        return 1;
    }

    return queue[front]; 
}

int getvalue(void){
    int value;
    printf("value: ");
    scanf("%i", &value);
    return value;
}

void display(){
    printf("queue: [");
    for (int i = front; i <= rear; i++){
        if (i != -1){
            printf("%d", queue[i]);
        }
        if (i != rear){
            printf(",");
        }
    }
    printf("]\n");
}