// Write a program to implement following operations on the circular linked list.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* HEAD = NULL;

struct node* getNode(int position);
int getvalue(char ask[]);
void insert(int value, int position);
void delete(int position);
void displayList();
void freeList();

int main(void){
    int keepRunning = 1, choice = 3;
    char options[3][10] = {{"insert"}, {"delete"}, {"exit"}};
    for (int i = 0; i < 3; i++){
        printf("%d: %s\n", i + 1, options[i]);
    }

    while (keepRunning){
        displayList();
        printf("choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice){
            case 1:
                insert(getvalue("value: "), getvalue("position: "));
                break;
            case 2:
                delete(getvalue("position: "));
                break;
            case 3:
                keepRunning = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    freeList();
    return 0;
}


struct node* getNode(int position){
    if (HEAD == NULL){
        printf("List Empty.\n");
        return NULL;
    }
    struct node* crawler = HEAD;
    for (int cur = 1; cur < position && crawler->next != HEAD; cur++) {
        crawler = crawler->next;
    }

    return crawler;
}

void delete(int position){
    if (HEAD == NULL){
        printf("List Empty.\n");
        return;
    }

    if (position == 1){
        if (HEAD->next == HEAD) {
            // Only one node in the list
            free(HEAD);
            HEAD = NULL;
            return;
        }
        // Find the last node to update its next pointer
        struct node* last = HEAD;
        while (last->next != HEAD) {
            last = last->next;
        }
        struct node* temp = HEAD;
        HEAD = temp->next;
        last->next = HEAD;
        free(temp);
        return;
    }

    struct node* nodeBeforePosition = getNode(position-1);
    if (nodeBeforePosition == NULL || nodeBeforePosition->next == HEAD){
        printf("Invalid Position.\n");
        return;
    }
    struct node* temp = nodeBeforePosition->next;
    nodeBeforePosition->next = temp->next;
    free(temp);
}

void insert(int value, int position){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL){
        printf("malloc failed\n");
        return;
    }
    new->data = value;

    if (HEAD == NULL){
        new->next = new;  // Point to itself
        HEAD = new;
        return;
    }

    if (position == 1){
        // Find the last node to update its next pointer
        struct node* last = HEAD;
        while (last->next != HEAD) {
            last = last->next;
        }
        new->next = HEAD;
        last->next = new;
        HEAD = new;
        return;
    }

    struct node* nodeBeforePosition = getNode(position-1);
    if (nodeBeforePosition == NULL){
        printf("Invalid Position.\n");
        free(new);
        return;
    }
    new->next = nodeBeforePosition->next;
    nodeBeforePosition->next = new;
}

void displayList(){
    if (HEAD == NULL){
        printf("List Empty.\n");
        return;
    }
    struct node* crawler = HEAD;
    do {
        printf("%d -> ", crawler->data);
        crawler = crawler->next;
    } while (crawler != HEAD);
    printf("(back to HEAD)\n");
}

int getvalue(char ask[]){
    int to_return;
    printf("%s", ask);
    scanf("%i", &to_return);
    return to_return;
}

void freeList(){
    if (HEAD == NULL) return;
    
    struct node* current = HEAD;
    struct node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != HEAD);
    HEAD = NULL;
}
