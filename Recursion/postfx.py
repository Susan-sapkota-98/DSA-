def postfix(expression):
    stack = [] 
    operators = {'+', '-', '*', '/', '^'}  

    for token in expression.split():
        if token not in operators:
           
            stack.append(int(token))  
        else:
            b = stack.pop()
            a = stack.pop()

            if token == '+':
                result = a + b
            elif token == '-':
                result = a - b
            elif token == '*':
                result = a * b
            elif token == '/':
                result = a / b
            elif token == '^':
                result = a ** b

            stack.append(result)

    return stack[0]

expression = input("Enter a postfix expression: ")
result = postfix(expression)
print("Result:", result)
