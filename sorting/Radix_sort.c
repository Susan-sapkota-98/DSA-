#include <stdio.h>
#include <stdlib.h>

int get_max(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void count_sort(int A[], int n, int pos)
{
    int output[n];       
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(A[i] / pos) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (A[i] / pos) % 10;
        output[--count[digit]] = A[i];
    }

    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

void radix_sort(int A[], int n)
{
    int max = get_max(A, n);
    for (int pos = 1; max / pos > 0; pos *= 10)
        count_sort(A, n, pos);
}

int main()
{
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A) / sizeof(A[0]);

    radix_sort(A, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
