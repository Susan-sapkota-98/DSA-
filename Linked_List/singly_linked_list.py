class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
first=last=None

def display():
    global first

    if first is None:
        print("List is Empty")
    else:
        temp=first
        while temp !=None:
            print(f"{temp.data} -> ",end="")
            temp=temp.next
        print("NULL")
        
def insert_at_beginning(element):
    global first,last
    NewNode=Node(element)
    NewNode.next=None
    if first is None:
        first=last=NewNode
    else:
        NewNode.next=first;
        first=NewNode;
    print(f"{element} was inserted!")

def insert_at_end(element):
    global first,last
    NewNode=Node(element)
    NewNode.next=None
    if first is None:
        first=last=NewNode
    else:
        last.next=NewNode;
        last=NewNode;
    print(f"{element} was inserted!")

def insert_at_specific(element, pos):
    global first, last
    if pos <= 0:
        print("Invalid position")
        return
    if pos == 1 or first is None:
        insert_at_beginning(element)
        return

    temp = first
    i = 1
    while i < pos - 1 and temp.next is not None:
        temp = temp.next
        i += 1

    if temp == last:
        insert_at_end(element)
    elif temp is not None:
        NewNode = Node(element)
        NewNode.next = temp.next
        temp.next = NewNode
        print(f"{element} was inserted ")
    else:
        print("Position out of range")

def delete_from_beginning():
    global first,last
    if first is None:
        print("List is empty")
    elif first.next is None:
        temp=first
        first=last=None
    else:
        temp=first
        print(f"{first.data} was deleted")
        first=first.next

def delete_from_end():
    global first, last
    if first is None:
        print("List is empty")
    elif first.next is None:
        print(f"{first.data} is going to be deleted")
        first = last = None
    else:
        temp = first
        while temp.next != last:
            temp = temp.next
        print(f"{last.data} was deleted")
        last = temp
        last.next = None

def delete_from_specific(pos):
    global first, last
    if pos <= 0 or first is None:
        print("Invalid deletion")
        return
    if pos == 1:
        delete_from_beginning()
        return

    temp = first
    i = 1
    while i < pos - 1 and temp.next != last:
        temp = temp.next
        i += 1

    if temp.next == last:
        delete_from_end()
    else:
        to_delete = temp.next
        temp.next = to_delete.next
        print(f"{to_delete.data} is deleted")

insert_at_beginning(20)
insert_at_beginning(30)
insert_at_beginning(40)
insert_at_beginning(50)
display()
insert_at_end(60)
insert_at_end(70)
display()
insert_at_specific(80,2)
insert_at_specific(90,4)
display()

delete_from_beginning()
display()

delete_from_end()
delete_from_end()
display()

delete_from_specific(2)
delete_from_specific(4)
display()
