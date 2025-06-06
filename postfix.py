# 2 3 + 

a = input("Enter your expression")

exp= a.split()
S = []

print(exp)
op2,op1=0,0
#scanning part 
for token in exp:
    print("scanned token:",token)
    
    if token!="+"or token!="*" or token!="^" or token != "/":
        S.append(int(token))
    else:
        result =0
        for token in exp:
            if token =="+":
                op1=S.pop()
                op2=S.pop()
                result op2+op1
            if token =="-":
                op1=S.pop()
                op2=S.pop()
                result op2-op1
            if token =="/":
                op1=S.pop()
                op2=S.pop()
                result (op2)/(op1)
            if token =="^":
                op1=S.pop()
                op2=S.pop()
                result (op2)**(op1)
            if token =="*":
                op1=S.pop()
                op2=S.pop()
                result (op2)*(op1)
          
# operator nikalne part

