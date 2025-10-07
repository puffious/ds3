// Implement Queue using Linked List
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

int enqueue(int value);
int dequeue(void);
int peep(void);
void display(void);
int getvalue(void);

int main(void){
    int keepRunning = 1, choice = 0;
    char options[5][10] = {{"enqueue"}, {"dequeue"}, {"peep"}, {"display"}, {"exit"}};
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
            case 1: // enqueue
                enqueue(getvalue());
                break;

            case 2: // dequeue
                printf("removed %d\n", dequeue());
                break;

            case 3: // peep
                printf("on front: %d\n", peep());
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
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Queue Overflow\n");
        return 1;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL){
        front = rear = newNode;
        return 0;
    }
    rear->next = newNode;
    rear = newNode;
    return 0;
}

int dequeue(void){
    if (front == NULL){
        printf("Queue Underflow\n");
        return 0;
    }
    struct node* temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL){
        rear = NULL;
    }
    free(temp);
    return value;
}

int peep(void){
    if (front == NULL){
        printf("Queue Underflow\n");
        return 0;
    }
    return front->data;
}

void display(void){
    printf("queue: [");
    struct node* temp = front;
    while (temp != NULL){
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