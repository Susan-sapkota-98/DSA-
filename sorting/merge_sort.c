#include <stdio.h>
#include <stdlib.h>

// Merges two sorted subarrays A[l..m] and A[m+1..r]
void merge(int A[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;

    // Temporary array to store merged result
    int B[100]; // Assuming array size won't exceed 100

    while (i <= m && j <= r)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left subarray
    while (i <= m)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    // Copy remaining elements from right subarray
    while (j <= r)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    // Copy merged elements back to original array
    for (int p = l; p <= r; p++)
    {
        A[p] = B[p];
    }
}

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    mergeSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
