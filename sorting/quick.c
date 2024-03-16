#include <stdio.h>
#define n 8
void display(int array[])
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
void swapp(int *x, int *y)
{
    int temp;
    temp = *y;
    *y = *x;
    *x = temp;
}
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swapp(&array[i], &array[j]);
            display(array);
        }
    }
    swapp(&array[i + 1], &array[high]);
    return (i + 1);
}
void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}
int main()
{
    int arr[8] = {5, 3, 2, 6, 4, 1, 3, 7};
    quicksort(arr, 0, n-1);
    display(arr);
    return 0;
}