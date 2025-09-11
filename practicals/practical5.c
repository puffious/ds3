// tower of hanoi using recursion

#include <stdio.h>

void hanoi(int n, char from_disk, char aux, char to_disk)
{
    if (n == 1)
    {
        printf("Moving disk %d from %c to %c \n", n, from_disk, to_disk);
        return;
    }

    // moving the (n-1)th disk to aux tower
    hanoi(n - 1, from_disk, to_disk, aux);
    printf("Moving disk %d from %c to %c \n", n, from_disk, to_disk);

    // moving the (n-1)th disk from aux to destination
    hanoi(n - 1, aux, from_disk, to_disk);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\n Moves \n");
    hanoi(n, 'A', 'B', 'C');
}