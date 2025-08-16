// Program to demonstrate the concepts of Call by Value and Call by reference.
// demonstrating swapping of values using afore mentioned concepts

#include <stdio.h>

int a, b;

int byValue(){
    // swap variables by value (taken from global scope)
    int temp = a;
    a = b;
    b = temp;
    return a, b;
}

void byReference(int *a, int *b){
    // swap variables by reference (address taken as arguments)
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    printf("insert two values (a, b): ");
    scanf("%d, %d", &a, &b);

    printf("Before Swap : %d, %d\n", a, b);
    byValue();
    printf("After Swap (by value): %d, %d\n", a, b);

    printf("Before Swap: %d, %d\n", a, b);
    byReference(&a, &b);
    printf("After Swap (by reference): %d, %d\n", a, b);

    return 0;
}
