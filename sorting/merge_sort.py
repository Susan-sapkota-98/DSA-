def merge(arr, l, m, r):
    # Create left and right subarrays
    left = arr[l:m+1]
    right = arr[m+1:r+1]

    i = j = 0  # Pointers for left and right
    k = l      # Pointer for merged array

    # Merge left and right into arr
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    # Copy remaining elements of left, if any
    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1

    # Copy remaining elements of right, if any
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1

def merge_sort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        merge_sort(arr, l, m)
        merge_sort(arr, m + 1, r)
        merge(arr, l, m, r)

# Example usage
arr = [38, 27, 43, 3, 9, 82, 10]
print("Original array:", arr)
merge_sort(arr, 0, len(arr) - 1)
print("Sorted array:", arr)
