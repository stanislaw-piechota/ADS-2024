#include <iostream>
#include <assert.h>

#define MAX_SIZE 100
#define EMPTY -1

class Stack
{
    public:
    int values[MAX_SIZE];
    int index = EMPTY;

    bool push(int value){
        if (index >= MAX_SIZE)
            return false;

        values[++index] = value;
        return true;
    }

    int pop(){
        assert(!isEmpty());
        return values[index--];
    }

    bool isEmpty(){
        return (index <= EMPTY);
    }

    int top(){
        assert(!isEmpty());
        return *(values + index);
    }
};

int main(int argc, char const *argv[])
{
    Stack test_stack = Stack();

    for (int i=1; i<=100; i++){
        test_stack.push(i);
    }

    return 0;
}
