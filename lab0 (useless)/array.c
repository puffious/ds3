#include <stdio.h>

int populate(int size, int array[]);
int dele(int index, int array[], int size);
int prnt(int array[], int size);
int insert(int value, int position, int size, int array[]);

int main(void){
    int size;
    printf("size of array: ");
    scanf("%d", &size);

    int array[size];
    populate(size, array);
    prnt(array, size);
    int value, index;
    printf("value & index to add (value, index): ");
    scanf("%d,%d", &value, &index);
    // dele(index, array, size);
    // prnt(array, size);
    insert(value, index, size, array);
}

int populate(int size, int array[]){
    for (int i = 0; i < size; i++){
        printf("index %i: ", i);
        scanf("%d", &array[i]);
    }
}

int insert(int value, int position, int size, int array[]){
    int temp[size+1];
    // copy values from original array to temp
    for (int i = 0; i < size; i++){
        if (i != size+1)
            temp[i] = array[i];
        else temp[i] = 0;
    }

    // shift position of all elements to make space for new value
    for (int i = size+1; i > position; i--){
        temp[i] = temp[i-1];
    }

    temp[position] = value;
    prnt(temp, size+1);
    
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