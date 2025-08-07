#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int A[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= n && A[l] > A[largest])
        largest = l;
    if (r <= n && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        maxHeapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{

    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(A, n, i);
    }

    for (int i = n; i >= 2; i--)
    {
        swap(&A[1], &A[i]);
        maxHeapify(A, i - 1, 1);
    }
}

int main()
{
    int A[] = {0, 4, 10, 3, 5, 1}; 
    int n = 5;

    heapSort(A, n);

    printf("Sorted array: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
