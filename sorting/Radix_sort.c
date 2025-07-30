#include <stdio.h>
#include <stdlib.h>

// Function to get maximum value in the array
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

// Counting Sort used by Radix Sort
void count_sort(int A[], int n, int pos)
{
    int output[n];       // Output array
    int count[10] = {0}; // For digits 0-9

    // Count occurrences of each digit at 'pos'
    for (int i = 0; i < n; i++)
        count[(A[i] / pos) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort)
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (A[i] / pos) % 10;
        output[--count[digit]] = A[i];
    }

    // Copy output to original array
    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

// Main Radix Sort function
void radix_sort(int A[], int n)
{
    int max = get_max(A, n);
    for (int pos = 1; max / pos > 0; pos *= 10)
        count_sort(A, n, pos);
}

// Driver code
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
