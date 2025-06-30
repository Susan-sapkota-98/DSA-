def tail(n,a):
    if n==1:
        return a
    else:
        return tail(n-1,a*n)
n=int(input("please enter the value of n: "))
result=tail(n,1)
print(f"the Tail recursive is : {result}")
