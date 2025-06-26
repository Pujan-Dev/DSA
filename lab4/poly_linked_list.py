'''
algorithm
suppose i got the eqn 3x^2 + 2x^2 + 1x^0
coeff (var) pow + ....

insert data:
new node = ...
if head is empty or head.power < new power
    then add new node as head and done
else
    temp = head
    then traverse the list while temp.next.power >= new power
        temp = temp.next

    if temp.power == new power
        temp.coeff += coeff
    else
        new.next, temp.next = temp.next, new

display()
    traverse list and print coeff x^power joined by +

evaluate(x)
    traverse list and calculate sum of coeff * (x ^ power)
'''
class Node:
    def __init__(self, coeff, power):
        self.coeff, self.power, self.next = coeff, power, None

class Polynomial:
    def __init__(self):
        self.head = None

    def insert(self, coeff, power):
        new = Node(coeff, power)
        if not self.head or self.head.power < power:
            new.next, self.head = self.head, new
        else:
            temp = self.head
            while temp.next and temp.next.power >= power:
                temp = temp.next
            if temp.power == power:
                temp.coeff += coeff
            else:
                new.next, temp.next = temp.next, new

 
    def display(self):
        temp = self.head
        terms = []
        while temp:
            terms.append(f"{temp.coeff}x^{temp.power}")
            temp = temp.next
            print(terms)

        print(" + ".join(terms))

    def evaluate(self, x):
        temp = self.head
        result = 0
        while temp:
            result += temp.coeff * (x ** temp.power)
            temp = temp.next
        return result


poly = Polynomial()
for c, p in [(3,2), (2,1), (1,0)]:
    poly.insert(c, p)

poly.display()
print("Value at x = 2:", poly.evaluate(2))

