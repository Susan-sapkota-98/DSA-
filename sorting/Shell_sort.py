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
        gap //=2


arr=[15,17,7,2,1,7,3,11]
print("original array:", arr)
shell_sort(arr)

print("sorted array is:", arr)
