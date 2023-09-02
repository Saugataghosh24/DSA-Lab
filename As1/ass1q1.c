#include <stdio.h>
void delElement(int *arr,int n, int index)
{
    for (int i = index; i < (n - 1); i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int i, n, index, arr[100];
    n = 10;
    printf("Enter 10 elements of the array ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    delElement(arr, n, 3);
    delElement(arr, n, 6);
    printf("5th Element: %d", arr[5]);
    return 0;
}
