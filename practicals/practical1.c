#include <stdio.h>
void call_value(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void call_referance(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n, m;
    printf("Name: Vaishvik Parekh \n");
    printf("Enrollment no: 240410107104 \n");
    printf("enter n1:");
    scanf("%d", &n);
    printf("enter n2:");
    scanf("%d", &m);
    printf("befor swaping n = %d and m = %d\n", n, m);
    call_value(n, m);
    printf("after swap using call by value n = %d and m= %d\n", n, m);
    call_referance(&n, &m);
    printf("after swap using call by referance n = %d, m = %d\n", n, m);
    return 0;
}
