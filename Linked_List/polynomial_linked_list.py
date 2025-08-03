#How can you  solve the polynomial equations using Linked  List
import math
class Node:
    def __init__(self, coeff, expo):
        self.coeff = coeff
        self.expo = expo
        self.link = None

class Polynomial:
    def __init__(self):
        self.head = None

    def insert(self, coeff, expo):
        new_node = Node(coeff, expo)
    
        if self.head is None or expo > self.head.expo:
            new_node.link = self.head
            self.head = new_node
        else:
            temp = self.head
            while temp.link is not None and temp.link.expo > expo:
                temp = temp.link

           
            if temp.link is not None and temp.link.expo == expo:
                temp.link.coeff += coeff
            else:
                new_node.link = temp.link
                temp.link = new_node

    def create(self):
        n = int(input("Enter the number of terms: "))
        for i in range(1, n + 1):
            coeff = float(input(f"Enter coefficient for term {i}: "))
            expo = int(input(f"Enter exponent for term {i}: "))
            self.insert(coeff, expo)

    def display(self):
        if self.head is None:
            print("Polynomial is empty")
        else:
            temp = self.head
            while temp is not None:
                print(f"({temp.coeff:.1f})x^{temp.expo}", end="")
                temp = temp.link
                if temp is not None:
                    print(" + ", end="")
            print()

    def evaluate(self, x):
        result = 0.0
        temp = self.head
        while temp is not None:
            result += temp.coeff * math.pow(x, temp.expo)
            temp = temp.link
        return result



poly = Polynomial()
print("Enter the polynomial:")
poly.create()

print("The polynomial is: ")
poly.display()

x = float(input("Enter the value of x to evaluate: "))
result = poly.evaluate(x)
print(f"Result of polynomial when x = {x:.2f} is:\n {result:.2f}")
