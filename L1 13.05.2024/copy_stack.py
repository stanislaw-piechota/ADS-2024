MAXIMUM_LENGTH = 1000

class Stack:
    """Implementation of Stack for exercise 1.1"""
    def __init__(self):
        self.values = [0 for _ in range(MAXIMUM_LENGTH)]
        self.index = -1

    def push(self, value: int) -> bool:
        if self.index >= MAXIMUM_LENGTH - 1:
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
    my_stack = Stack()

    try:
        print(f"Last value: {my_stack.pop()}")
    except AssertionError as error:
        print(error)
        print("Blocking invalid operation is working")

    i = 0
    while my_stack.push(i):
        i += 1
    print(f"Push nr {i+1} returned not successful")
    print(my_stack)

    while not my_stack.is_empty():
        print(f"The last element: {my_stack.top()}, index pointing to {my_stack.index}")
        print(f"Removed last element: {my_stack.pop()}, index pointing to {my_stack.index}")
        print(f"New last element: {my_stack.top()}, index pointing to {my_stack.index}")
        print("\n\n")


if __name__ == "__main__":
    infix = input("> ")
