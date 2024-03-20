#include <stdio.h>
#define size 6
void merge(int arr[], int low, int m, int high)
{
    int i, j, k;
    int n1 = m - low + 1;
    int n2 = high - m;
    int L[n1], M[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++)
    {
        M[j] = arr[m + 1 + j];
    }
    i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int m = (low + high) / 2;
        mergesort(arr, low, m);
        mergesort(arr, m + 1, high);
        merge(arr, low, m, high);
    }
}
int main()
{
    int arr[size] = {6, 5, 12, 10, 9, 1};
    mergesort(arr, 0, size - 1);
    int i = 0;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}