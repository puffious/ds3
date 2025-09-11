// addition, subtraction and multiplication on 3x3 matrix
#include <stdio.h>
#include <stdlib.h>

void add();
void sub();
void multiply();

int a[3][3], b[3][3];

int main()
{
    int choice;

    printf("Enter matrix A elements: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter matrix B elements: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    while (1)
    {
        printf("\n 1: Add");
        printf("\n 2: Subtract");
        printf("\n 3: Multiplication");
        printf("\n 4: Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add();
            break;

        case 2:
            sub();
            break;

        case 3:
            multiply();
            break;

        case 4:
            exit(0);

        default:
            printf("\n Enter a valid value... ");
        }
    }

    return 0;
}

void add()
{
    int c[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d \t", c[i][j]);
        }
        printf("\n");
    }
}

void sub()
{
    int c[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d \t", c[i][j]);
        }
        printf("\n");
    }
}

void multiply()
{
    int c[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                c[i][j] += a[i][k] + b[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d \t", c[i][j]);
        }
        printf("\n");
    }
}