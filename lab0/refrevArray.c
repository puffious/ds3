// reverse array using reference

#include <stdio.h>

int prntpt(int *pt){
    for (int i = 4; i >= 0; i--){
        printf("%d\t", pt[i]);
    }
    printf("\n");
}

int main(void){
    int arr[5] = {1, 2, 3, 4, 5};
    int *pt = arr;
    prntpt(pt);
}
