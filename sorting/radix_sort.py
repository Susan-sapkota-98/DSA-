def get_max(arr):
    return max(arr)

def count_sort(arr, pos):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    # Count occurrences of digits at the given position
    for i in range(n):
        index = (arr[i] // pos) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]
        
    i=n-1
    while i>=0:
        digit=(arr[i]//pos)%10
        output[count[digit]-1]=arr[i]
        count[digit] -= 1
        i -=1

    
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    max_val = get_max(arr)
    pos = 1
    while max_val // pos > 0:
        count_sort(arr, pos)
        pos *= 10


arr = [15,17,7,2,1,7,3,11]
radix_sort(arr)
print(" The Sorted array is:", arr)
