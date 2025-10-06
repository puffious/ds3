// Write a program which create binary search tree. Also write a function to search an element from binary search tree

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* ROOT = NULL;

struct node* createNode(int value);
struct node* insert(struct node* root, int value);
struct node* search(struct node* root, int value);
void inorderTraversal(struct node* root);
void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);
void freeTree(struct node* root);
int getvalue(char ask[]);

int main(void){
    int keepRunning = 1, choice = 0, value = 0;
    char options[5][15] = {{"insert"}, {"search"}, {"inorder"}, {"preorder"}, {"exit"}};
    for (int i = 0; i < 5; i++){
        printf("%d: %s\n", i + 1, options[i]);
    }

    while (keepRunning){
        printf("\nBST (inorder): ");
        inorderTraversal(ROOT);
        printf("\n");
        
        printf("choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice){
            case 1: // insert
                ROOT = insert(ROOT, getvalue("value: "));
                break;
            case 2: // search
                value = getvalue("search value: ");
                if (search(ROOT, value) != NULL){
                    printf("Element %d found in BST\n", value);
                } else {
                    printf("Element %d not found in BST\n", value);
                }
                break;
            case 3: // inorder
                printf("Inorder: ");
                inorderTraversal(ROOT);
                printf("\n");
                break;
            case 4: // preorder
                printf("Preorder: ");
                preorderTraversal(ROOT);
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
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL){
        printf("malloc failed\n");
        return NULL;
    }
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node* insert(struct node* root, int value){
    if (root == NULL){
        return createNode(value);
    }

    if (value < root->data){
        root->left = insert(root->left, value);
    } else if (value > root->data){
        root->right = insert(root->right, value);
    } else {
        printf("Duplicate value %d not inserted\n", value);
    }

    return root;
}

struct node* search(struct node* root, int value){
    if (root == NULL || root->data == value){
        return root;
    }

    if (value < root->data){
        return search(root->left, value);
    }

    return search(root->right, value);
}

void inorderTraversal(struct node* root){
    if (root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node* root){
    if (root != NULL){
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node* root){
    if (root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
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