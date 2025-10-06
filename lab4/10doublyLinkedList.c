// Write a menu driven program to perform operations on the doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
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
    for (int cur = 1; cur < position && crawler->next != NULL; cur++) {
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
        struct node* temp = HEAD;
        HEAD = temp->next;
        if (HEAD != NULL) {
            HEAD->prev = NULL;
        }
        free(temp);
        return;
    }

    struct node* nodeBeforePosition = getNode(position-1);
    if (nodeBeforePosition == NULL || nodeBeforePosition->next == NULL){
        printf("Invalid Position.\n");
        return;
    }
    struct node* temp = nodeBeforePosition->next;
    nodeBeforePosition->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = nodeBeforePosition;
    }
    free(temp);
}

void insert(int value, int position){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL){
        printf("malloc failed\n");
        return;
    }
    new->data = value;
    new->prev = NULL;
    new->next = NULL;

    if (position == 1 || HEAD == NULL){
        new->next = HEAD;
        if (HEAD != NULL) {
            HEAD->prev = new;
        }
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
    new->prev = nodeBeforePosition;
    if (nodeBeforePosition->next != NULL) {
        nodeBeforePosition->next->prev = new;
    }
    nodeBeforePosition->next = new;
}

void displayList(){
    if (HEAD == NULL){
        printf("List Empty.\n");
        return;
    }
    struct node* crawler = HEAD;
    while (crawler != NULL){
        printf("%d -> ", crawler->data);
        crawler = crawler->next;
    }
    printf("NULL\n");
}

int getvalue(char ask[]){
    int to_return;
    printf("%s", ask);
    scanf("%i", &to_return);
    return to_return;
}

void freeList(){
    struct node* current = HEAD;
    struct node* next;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    HEAD = NULL;
}
