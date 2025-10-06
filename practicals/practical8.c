// Singly Linked List operations in C

#include <stdio.h>
#include <stdlib.h>

// Node structure (self-referential)
struct Node
{
    int data;           // data stored in the node
    struct Node *next;  // pointer to the next node in the list
};

// Head pointer (points to the first node of the list)
struct Node *head = NULL;

// Function to insert a new node at the beginning of the list
void insert_at_beginning(int value)
{
    // Step 1: Allocate memory for the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    // Step 2: Assign data and adjust pointers
    newNode->data = value;
    newNode->next = head;  // new node will point to the current head
    head = newNode;        // update head to point to the new node

    printf("Inserted %d at the beginning.\n", value);
}

// Function to insert a new node at the end of the list
void insert_at_end(int value)
{
    // Step 1: Allocate memory for the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // Step 2: If list is empty, new node becomes head
    if (head == NULL)
    {
        head = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    // Step 3: Otherwise, traverse to the last node
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Step 4: Link the last node to the new node
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

// Function to insert a node in ascending order (sorted list insert)
void insert_in_ascending(int value)
{
    // Step 1: Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // Step 2: If list is empty or first node is bigger, insert at beginning
    if (head == NULL || head->data >= value)
    {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d in ascending order.\n", value);
        return;
    }

    // Step 3: Find position to insert
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }

    // Step 4: Insert the node
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d in ascending order.\n", value);
}

// Function to delete the first node of the list
void delete_from_beginning()
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;  // move head to the next node
    printf("Deleted node with value %d from the beginning.\n", temp->data);

    free(temp);  // free the memory
}

// Function to delete a node with a given value
void delete_given(int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    // Case 1: If head node itself holds the value
    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        printf("Deleted node with value %d.\n", temp->data);
        free(temp);
        return;
    }

    // Case 2: Search for the value
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

    // Unlink the node
    prev->next = temp->next;
    printf("Deleted node with value %d.\n", temp->data);
    free(temp);
}

// Function to delete the node after a given value
void delete_after_given(int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = head;

    // Search for the given value
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Node %d not found or it is the last node.\n", value);
        return;
    }

    // Delete the node after it
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;

    printf("Deleted node with value %d, which was after %d.\n", toDelete->data, value);
    free(toDelete);
}

// Function to display the linked list
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

// Main function (menu-driven program)
int main()
{
    int choice, value, count;

    while (1)
    {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert in ascending order\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete a given node\n");
        printf("6. Delete node after a given node\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter how many nodes to insert at beginning: ");
            scanf("%d", &count);
            for (int i = 0; i < count; i++)
            {
                printf("Enter value: ");
                scanf("%d", &value);
                insert_at_beginning(value);
            }
            break;

        case 2:
            printf("Enter how many nodes to insert at end: ");
            scanf("%d", &count);
            for (int i = 0; i < count; i++)
            {
                printf("Enter value: ");
                scanf("%d", &value);
                insert_at_end(value);
            }
            break;

        case 3:
            printf("Enter value to insert in ascending order: ");
            scanf("%d", &value);
            insert_in_ascending(value);
            break;

        case 4:
            printf("Enter how many nodes to delete from beginning: ");
            scanf("%d", &count);
            for (int i = 0; i < count; i++)
            {
                delete_from_beginning();
            }
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
