// Implement a circular queue using arrays and demonstrate its operations.
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
    if (rear >= size-1 && front == 0 || front == rear+1){ // queue is full
        printf("Queue OverFlow\n");
        return 1;
    }
    else if (front == -1) front = rear = 0; // first element
    else if (rear == size-1 && front != 0) rear = 0; // wrap around
    else rear ++; // normal increment
    queue[rear] = value;
    return 0;
}

int dequeue(void){
    if (front == -1){
        printf("Queue UnderFlow\n");
        return 0;
    }

    int value = queue[front];

    if (front == rear) front = rear = -1; // last element
    else if (front == size - 1) front = 0; // wrap around
    else front ++;

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
    if (front == -1) {
        printf("queue: []\n");
        return;
    }
    
    printf("queue: [");
    if (rear >= front) {
        // No wrap around
        for (int i = front; i <= rear; i++){
            printf("%d", queue[i]);
            if (i != rear) printf(",");
        }
    } else {
        // Wrapped around: front to end, then 0 to rear
        for (int i = front; i < size; i++){
            printf("%d,", queue[i]);
        }
        for (int i = 0; i <= rear; i++){
            printf("%d", queue[i]);
            if (i != rear) printf(",");
        }
    }
    printf("]\n");
}