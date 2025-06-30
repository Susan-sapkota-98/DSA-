class Node:
    def __init__(self, coeff, expo):
        self.coeff = coeff
        self.expo = expo
        self.link = None

def insert(head, coeff, expo):
    new_node = Node(coeff, expo)

    if head is None or expo > head.expo:
        new_node.link = head
        head = new_node
    else:
        temp = head
        while temp.link is not None and temp.link.expo > expo:
            temp = temp.link
        new_node.link = temp.link
        temp.link = new_node

    return head

def create():
    head = None
    n = int(input("Enter the number of terms: "))
    for i in range(1, n + 1):
        coeff = float(input(f"Enter the coefficient for term {i} : "))
        expo = int(input(f"Enter the exponent for term {i} : "))
        head = insert(head, coeff, expo)
    return head

def display(head):
    if head is None:
        print("No polynomial")
    else:
        temp = head
        while temp is not None:
            print(f"({temp.coeff:.1f})x^{temp.expo}", end="")
            temp = temp.link
            if temp is not None:
                print(" + ", end="")
            else:
                print()

# Main part
print("Enter the polynomial")
head = create()
display(head)
