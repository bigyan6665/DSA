#include <stdio.h>
#define n 6
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void display(int a[], int size)
{
    for (int k = 0; k < size; k++)
    {
        printf("%d\t", a[k]);
    }
}
int main()
{
    int i, j, min;
    int a[n] = {7, 4, 10, 8, 3, 1};
    printf("Input : ");
    display(a, n);
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
        printf("\npass%d : ", i + 1);
        display(a, n);
    }
    printf("\nSorted : ");
    display(a, n);
    return 0;
}