from stack import Stack

def is_balanced(input_str: str) -> bool:
    stack = Stack()
    
    for s in input_str:
        if s == '(':
            stack.push(s)
        elif s == ')':
            if stack.pop() is None:
                return False
    return stack.peek() is None
