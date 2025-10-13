// Write a program to implement binary search on a sorted array.
#include <stdio.h>

int binary_search(int arr[], int size, int key);

int main(void){
    int n, key;
    printf("Number of Elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++){
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binary_search(arr, n, key);
    if (result != -1){
        printf("Element found at index %d\n", result);
    }
    else{
        printf("Element not found\n");
    }

    return 0;
}

int binary_search(int arr[], int size, int key){
    int left = 0, right = size - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == key){
            return mid;
        }
        else if (arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}