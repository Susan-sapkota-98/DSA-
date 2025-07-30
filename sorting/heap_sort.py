def max_heapify(arr, n, i):
    largest = i
    l = 2 * i + 1  # left child = 2*i + 1
    r = 2 * i + 2  # right child = 2*i + 2

    # Check if left child is larger than root
    if l < n and arr[l] > arr[largest]:
        largest = l
    
    # Check if right child is larger than largest so far
    if r < n and arr[r] > arr[largest]:
        largest = r

    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap
        max_heapify(arr, n, largest)  # Recursively heapify the affected subtree

def heap_sort(arr):
    n = len(arr)

    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(arr, n, i)

    # Extract elements from the heap one by one
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap the root(maximum) with the last element
        max_heapify(arr, i, 0)  # Heapify the root of the tree


arr = [4, 10, 3, 5, 1]
heap_sort(arr)
print("Sorted array:", arr)
