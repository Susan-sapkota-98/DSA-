def GCD(a,b):
    if b==0:
        return a
    else:
        while b!=0:
            r=a%b
            a=b
            b=r
        return a

a=int(input("Enter the value of a: "))
b=int(input("Enter the value of b: "))
print(f'The GCD value is :{GCD(a,b)}')