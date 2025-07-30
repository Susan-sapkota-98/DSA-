def sum(n):
    if n==1:
        return 1
    else:
        return n+sum(n-1)

n=int(input("Please enter the value of n : "))
print(f'The sum of {n} natural number is : {sum(n)}')