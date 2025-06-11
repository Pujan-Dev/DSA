# postfix in stack using python

input = input("Enter the expression")

operators = ["*", "^", "+", "-", "/"]

stack = []


def evaluate(exp):
    errflag = False

    exp = exp.split(" ")
    for i in exp:
        print("scan", i)

        if i not in operators:
            stack.append(i)
        else:
            if i in operators:
                op2 = float(stack.pop())
                op1 = float(stack.pop())
                if i == "+":
                    result = op1 + op2
                    stack.append(result)
                elif i == "*":
                    result = op1 * op2
                    stack.append(result)
                elif i == "/":
                    if op2 == 0:
                        print("Error: Division by zero")
                        return
                    result = op1 / op2
                    stack.append(result)
                elif i == "^":
                    result = op1**op2
                    stack.append(result)
                elif i == "-":
                    result = op1 - op2
                    stack.append(result)

            else:
                print(f"the operator is invalid: {i}")
                errflag = True
                break
    if errflag:
        print("exiting")
    else:
        print(f"the final result: {stack.pop()}")


evaluate(input)
