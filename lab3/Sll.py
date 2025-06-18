class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


first = None
last = None


def Display():
    global first
    if first is None:
        print("The list is empty")
    else:
        temp = first
        while temp:
            print(f"{temp.data}->", end="")
            temp = temp.next
        print("Null")


def insert_at_beginning(element):
    global first, last
    new_node = Node(element)
    if first is None:
        first = last = new_node
    else:
        new_node.next = first
        first = new_node
    print(f"{element} was Inserted")


def insert_at_end(element):
    global first, last
    new_node = Node(element)
    if first is None:
        first = last = new_node
    else:
        last.next = new_node
        last = new_node
    print(f"{element} was Inserted")


def insert_at_specific_position(element, POS):
    global first, last
    if POS <= 0:
        print("Invalid Position")
    elif POS == 1 or first is None:
        insert_at_beginning(element)
    else:
        temp = first
        i = 1
        while i < POS - 1 and temp.next is not None: 
            temp = temp.next
            i += 1
        if temp == last:
            insert_at_end(element)
        else:
            new_node = Node(element)
            new_node.next = temp.next
            temp.next = new_node
            print(f"{element} was inserted")


def deletion_from_the_beginning():
    global first, last
    if first is None:
        print("List is Empty")
    elif first.next is None:
        print(f"{first.data} will be removed")
        first = last = None
    else:
        print(f"{first.data} will be removed")
        first = first.next


def deletion_from_the_end():
    global first, last
    if first is None:
        print("List is Empty")
    elif first.next is None:
        print(f"{first.data} will be removed")
        first = last = None
    else:
        temp = first
        while temp.next != last:
            temp = temp.next
        print(f"{last.data} will be removed")
        last = temp
        last.next = None


def deletion_from_the_specific_pos(POS):
    global first, last
    if POS <= 0 or first is None:
        print("Invalid Deletion")
    elif POS == 1:
        deletion_from_the_beginning()
    else:
        temp = first
        i = 1
        while i < POS - 1 and temp.next != last:
            temp = temp.next
            i += 1
        if temp.next == last:
            deletion_from_the_end()
        else:
            to_delete = temp.next
            temp.next = to_delete.next
            print(f"{to_delete.data} element deleted from the {POS} position")


insert_at_end(2)
Display()
insert_at_end(3)
Display()
insert_at_end(4)
Display()
insert_at_end(5)
Display()

insert_at_specific_position(400, 1)
Display()
insert_at_specific_position(300, 4)
Display()
insert_at_specific_position(600, 7)
Display()
deletion_from_the_beginning()
Display()
deletion_from_the_beginning()
Display()
deletion_from_the_end()
Display()
deletion_from_the_end()
Display()
deletion_from_the_specific_pos(2)
Display()
