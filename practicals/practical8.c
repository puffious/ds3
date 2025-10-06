#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_beginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Inserted %d at the beginning.\n", value);
}

void insert_at_end(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

void insert_in_ascending(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value)
    {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d in ascending order.\n", value);
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d in ascending order.\n", value);
}

void delete_from_beginning()
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    printf("Deleted node with value %d from the beginning.\n", temp->data);

    free(temp);
}

void delete_given(int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        printf("Deleted node with value %d.\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", value);
        return;
    }

    prev->next = temp->next;
    printf("Deleted node with value %d.\n", temp->data);
    free(temp);
}

void delete_after_given(int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Node %d not found or it is the last node.\n", value);
        return;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;

    printf("Deleted node with value %d, which was after %d.\n", toDelete->data, value);
    free(toDelete);
}

void display_list()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at beginning (single node)\n");
        printf("2. Insert at end (single node)\n");
        printf("3. Insert in ascending order (single node)\n");
        printf("4. Delete from beginning (single node)\n");
        printf("5. Delete a given node\n");
        printf("6. Delete node after a given node\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &value);
            insert_at_beginning(value);
            break;

        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insert_at_end(value);
            break;

        case 3:
            printf("Enter value to insert in ascending order: ");
            scanf("%d", &value);
            insert_in_ascending(value);
            break;

        case 4:
            delete_from_beginning();
            break;

        case 5:
            printf("Enter value of node to delete: ");
            scanf("%d", &value);
            delete_given(value);
            break;

        case 6:
            printf("Enter value of the preceding node: ");
            scanf("%d", &value);
            delete_after_given(value);
            break;

        case 7:
            display_list();
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
