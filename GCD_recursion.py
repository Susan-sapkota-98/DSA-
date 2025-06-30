def GCD(a,b):
    if(b==0):
        return a
    else:
        return GCD(b,a%b)
    
a=int(input("Enter the value of a: "))
b=int(input("Enter the value of b: "))
c=GCD(a,b)
print(f'The GCD result using recursion is : {c}')
