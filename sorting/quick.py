def quicksort(A,l,r):
    if(l,r):
        p=partition(A,l,r)
        quicksort(A,l,p-1)
        quicksort(A,p+1,r)

def partition(A,l,r):
    x=l
    y=r
    pivot=A[l]
    while(x<y):
        while(A[x]<=pivot):
            x++
        while(A[y]>pivot):
            y--
        if(x<y):
            swap(A[x],A[y])

def swap(A[l],A[y]):
    return y

data_list = list(map(int, input("Enter numbers separated by space: ").split()))

result = quicksort(data_list)
print("Sorted list:", result)