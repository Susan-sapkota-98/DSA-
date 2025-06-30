
def fibo(n):
    if n == 1 or n == 2:
        return 1
    elif table[n] == 0:
        table[n] = fibo(n - 1) + fibo(n - 2)
    return table[n]

n=int(input("Enter the value of n "))
table=[0]*(n+1)

result =fibo(n)
print(f'The {n}th term is {result}')

