# A=array l=low , r=high , pivot=p
def quicksort(A,l,r):
    if l<r:
        p=partition(A,l,r)
        quicksort(A,l,p-1)
        quicksort(A,p+1,r)

def partition(A,l,r):
    p=A[l]
    i=l+1
    j=r
    while True:
        while i<=j and A[i]<=p:
            i+=1
        while i<=j and A[j]>=p:
            j-=1
        if i<=j:
            A[i],A[j]=A[j],A[i]
        else:
            break
    A[l],A[j]=A[j],A[l]
    return j
    

nums = list(map(int, input("Enter numbers separated by space: ").split()))
print("The list of array before sorting:", nums)
quicksort(nums,0,len(nums)-1)
print("Sorted list:", nums)