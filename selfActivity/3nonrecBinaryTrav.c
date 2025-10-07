// Implement non-recursive tree traversing methods for a binary tree
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* ROOT = NULL;

struct node* createNode(int value);
struct node* insert(struct node* root, int value);
void inorderTraversal(struct node* root);
void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);
void freeTree(struct node* root);
int getvalue(char ask[]);

int main(void){
    int keepRunning = 1, choice = 0;
    char options[5][15] = {{"insert"}, {"inorder"}, {"preorder"}, {"postorder"}, {"exit"}};
    for (int i = 0; i < 5; i++){
        printf("%d: %s\n", i + 1, options[i]);
    }

    while (keepRunning){
        printf("\nBST (inorder): ");
        inorderTraversal(ROOT);
        printf("\n");
        
        printf("choice: ");
        if (scanf("%d", &choice) != 1){
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice){
            case 1: // insert
                ROOT = insert(ROOT, getvalue("value: "));
                break;
            case 2: // inorder
                printf("Inorder: ");
                inorderTraversal(ROOT);
                printf("\n");
                break;
            case 3: // preorder
                printf("Preorder: ");
                preorderTraversal(ROOT);
                printf("\n");
                break;
            case 4: // postorder
                printf("Postorder: ");
                postorderTraversal(ROOT);
                printf("\n");
                break;
            case 5: // exit
                keepRunning = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    freeTree(ROOT);
    return 0;
}

struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("malloc failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value){
    struct node* newNode = createNode(value);
    if (root == NULL){
        return newNode;
    }

    struct node* parent = NULL;
    struct node* current = root;

    while (current != NULL){
        parent = current;
        if (value < current->data){
            current = current->left;
        } else if (value > current->data){
            current = current->right;
        } else{
            printf("Duplicate value %d not inserted\n", value);
            free(newNode);
            return root;
        }
    }
    if (value < parent->data){
        parent->left = newNode;
    } else{
        parent->right = newNode;
    }

    return root;
}

void inorderTraversal(struct node* root){
    struct node* stack[MAX];
    int top = -1;
    struct node* curr = root;

    while (curr != NULL || top >= 0){
        while (curr != NULL){
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorderTraversal(struct node* root){
    if (root == NULL){
        return;
    }
    struct node* stack[MAX];
    int top = -1;

    stack[++top] = root;
    while (top >= 0){
        struct node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right){
            stack[++top] = curr->right;
        }
        if (curr->left){
            stack[++top] = curr->left;
        }
    }
}

void postorderTraversal(struct node* root){
    if (root == NULL){
        return;
    }
    struct node* stack1[MAX];
    struct node* stack2[MAX];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;
    while (top1 >= 0){
        struct node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left){
            stack1[++top1] = curr->left;
        }
        if (curr->right){
            stack1[++top1] = curr->right;
        }
    }
    while (top2 >= 0){
        printf("%d ", stack2[top2--]->data);
    }
}

void freeTree(struct node* root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int getvalue(char ask[]){
    int to_return;
    printf("%s", ask);
    scanf("%i", &to_return);
    return to_return;
}