#ifndef __STACK__

#define MAX_SIZE 1000
#define EMPTY -1

template <typename T = int>
class Stack
{
public:
    T values[MAX_SIZE - 1];
    int index = EMPTY;

    bool push(T value) {
        if (index >= MAX_SIZE - 1)
            return false;

        values[++index] = value;
        return true;
    }

    T pop() {
        if (isEmpty())
            throw (index);
        return values[index--];
    }

    bool isEmpty() {
        return (index <= EMPTY);
    }

    T top() {
        if(isEmpty())
            throw(index);
        return *(values + index);
    }
};

#endif