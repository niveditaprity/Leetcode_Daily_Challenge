class MyQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        self.stack1.append(x)
        self.stack2.append(self.stack1.pop())

    def pop(self) -> int:
        return self.stack2.pop(0)

    def peek(self) -> int:
        return self.stack2[0]

    def empty(self) -> bool:
        if not self.stack2:
            return True
        return False
        