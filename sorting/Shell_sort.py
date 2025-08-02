def shell_sort(arr):
    n=len(arr)
    gap=n//2

    while gap>0:
        for i  in range(gap,n):
            temp=arr[i]
            j=i

            while j>=gap and arr[j-gap]>temp:
                arr[j]=arr[j-gap]
                j-=gap

            arr[j]=temp
        gap =gap // 2


arr=[19,63,2,6,7,18,60,16,9,4]
print("original array:", arr)
shell_sort(arr)

print("sorted array is:", arr)
