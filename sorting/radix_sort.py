def count_sort(arr, pos):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(0,n):
        temp= (arr[i] // pos) % 10
        count[temp] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]
        
    i=n-1
    while i>=0:
        temp=(arr[i]//pos)%10
        output[count[temp]-1]=arr[i]
        count[temp] -= 1
        i =i-1

    for i in range(0,n):
        arr[i] = output[i]


def radix_sort(arr):
    max_val = max(arr)
    #for unit place pos=1
    pos = 1
    while max_val // pos > 0:
        count_sort(arr, pos)
        pos *= 10

arr = [157,15,7,20,1,72,333,111,605,225]
print("The original array is:", arr)
radix_sort(arr)
print("The Sorted array is:", arr)
