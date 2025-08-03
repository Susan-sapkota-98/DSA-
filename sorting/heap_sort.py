def max_heapify(arr, n, i):
    largest = i
    l = 2 *i + 1
    r = 2 * i + 2

    if l < n and arr[l] > arr[largest]:
        largest = l
    
    if r < n and arr[r] > arr[largest]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i] 
        max_heapify(arr, n, largest)  

def Build_Max_Heap(arr,n):
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(arr, n, i)

def heap_sort(arr,n):
    Build_Max_Heap(arr,n)
    
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  
        max_heapify(arr, i, 0)  


arr = list(map(int, input("Enter numbers separated by space: ").split()))
print("The array of list before sorting: ", arr)
heap_sort(arr,len(arr))
print("Sorted array:", arr)
