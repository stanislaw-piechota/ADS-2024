MAXIMUM_LENGTH = 1000

class Stack:
    """Implementation of Stack for exercise 1.1"""
    def __init__(self):
        self.values = [0 for _ in range(MAXIMUM_LENGTH)]
        self.index = -1

    def push(self, value: int) -> bool:
        if (self.index >= MAXIMUM_LENGTH - 1):
            return False
        
        self.index += 1
        self.values[self.index] = value
        return True
    
    def pop(self) -> int:
        assert not self.is_empty()
        self.index -= 1
        return self.values[self.index + 1]
    
    def is_empty(self) -> bool:
        return self.index <= -1
    
    def top(self) -> int:
        assert not self.is_empty()
        return self.values[self.index]
    
    def __repr__(self):
        return "[" + ' '.join([str(x) for x in self.values]) + "]"
    

def test_stack():
    test_stack = Stack()

    try:
        print(f"Last value: {test_stack.pop()}")
    except AssertionError as error:
        print(error)
        print("Blocking invalid operation is working")

    i = 0
    while test_stack.push(i):
        i += 1
    print(f"Push nr {i+1} returned not successful")
    print(test_stack)

    while not test_stack.is_empty():
        print(f"The last element: {test_stack.top()}, index pointing to {test_stack.index}")
        print(f"Removed last element: {test_stack.pop()}, index pointing to {test_stack.index}")
        print(f"New last element: {test_stack.top()}, index pointing to {test_stack.index}")
        print("\n\n")


if __name__ == "__main__":
    pass