from typing import Any

class Stack:
    def __init__(self) -> None:
        self.items: list[Any] = []

    def push(self, item: Any) -> None:
        self.items.append(item)
    
    def size(self) -> int:
        return len(self.items)

    def peek(self) -> Any:
        if self.size() < 1:
            print("Stack is empty")
            return None
        return self.items[-1]

    def pop(self) -> Any:
        if self.size() < 1:
            print("Stack is empty")
            return None

        p = self.items[-1]
        del self.items[-1]
        return p
