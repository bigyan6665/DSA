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
    int arr[n] = {7, 4, 10, 8, 3, 1};
    printf("Input : ");
    display(arr, n);
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[min], &arr[i]);
        }
        printf("\npass%d : ", i + 1);
        display(arr, n);
    }
    printf("\nSorted : ");
    display(arr, n);
    return 0;
}