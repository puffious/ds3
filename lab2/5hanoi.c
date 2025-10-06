// Implement the Tower of Hanoi problem using recursion
#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int N;
    printf("Number of disks: ");
    scanf("%d", &N);

    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}