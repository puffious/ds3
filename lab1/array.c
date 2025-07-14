#include <stdio.h>

int ins(int size, int array[]);
int dele(int index, int array[], int size);
int prnt(int array[], int size);

int main(void){
    int size;
    printf("size of array: ");
    scanf("%d", &size);
    int array[size];
    ins(size, array);
    prnt(array, size);
    int index;
    printf("index to delete: ");
    scanf("%d", &index);
    dele(index, array, size);
    prnt(array, size);
}

int ins(int size, int array[]){
    for (int i = 0; i < size; i++){
        printf("%dth index: ", i+1);
        scanf("%d", &array[i]);
    }
}

int dele(int index, int array[], int size){
    for (int i = 0; i < size; i++){
        if (i > index){
            array[i-1] = array[i];
        }
    }
}

int prnt(int array[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
}