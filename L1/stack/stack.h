#ifndef __STACK__

#include <assert.h>
#define MAX_SIZE 1000
#define EMPTY -1

template <typename T = int>
class Stack
{
public:
    T values[MAX_SIZE - 1];
    int index = EMPTY;
    
    bool push(T value){
        if (index >= MAX_SIZE - 1)
            return false;

        values[++index] = value;
        return true;
    }

    T pop(){
        assert(!isEmpty());
        return values[index--];
    }

    bool isEmpty(){
        return (index <= EMPTY);
    }

    T top(){
        assert(!isEmpty());
        return *(values + index);
    }
};

#endif