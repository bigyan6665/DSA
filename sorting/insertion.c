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
    int i, j, temp;
    int a[n] = {5, 4, 10, 1, 6, 2};
    printf("Input : ");
    display(a, n);
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
            printf("\n\t");
            display(a, n);
        }
        a[j + 1] = temp;
        printf("\npass%d : ", i);
        display(a, n);
    }
    printf("\nSorted : ");
    display(a, n);
    return 0;
}