"""
NOTE: more practice on stacks
https://neetcode.io/problems/validate-parentheses/question?list=neetcode150 -EASY
https://neetcode.io/problems/minimum-stack/question?list=neetcode150 -> MED
https://neetcode.io/problems/evaluate-reverse-polish-notation/question?list=neetcode150 -> MED
https://neetcode.io/problems/daily-temperatures/question?list=neetcode150 -> MED
https://neetcode.io/problems/car-fleet/question?list=neetcode150 -> MED
https://neetcode.io/problems/largest-rectangle-in-histogram/question?list=neetcode150 -> HARD
"""
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
