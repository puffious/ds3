// circular queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue();
void dequeue();
void print_queue();

int main()
{
    int choice;

    while (1)
    {
        printf("\nEnter your choice: \n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Print Queue \n");
        printf("4. Exit \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            print_queue();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Enter value between 1 and 4 \n");
        }
    }
    return 0;
}

// enqueue
void enqueue()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("\n Queue Full \n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        // initialize front if queue is empty
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d inserted \n", value);
    }
}

void dequeue()
{
    // if queue is empty
    if (front == -1)
    {
        printf("Queue Empty \n");
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n %d removed \n", queue[front]);
        front = (front + 1) % MAX;

        // queue became empty after removal, because only 1 element was present in the queue
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void print_queue()
{
    if (front == -1)
    {
        printf("Queue Empty \n");
    }
    else
    {
        // regular case where the queue is not wrapped around
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("| %d ", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < MAX; i++)
            {
                printf("| %d", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("| %d", queue[i]);
            }
        }

        printf("| \n");
    }
}
