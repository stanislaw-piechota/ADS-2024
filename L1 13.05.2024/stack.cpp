#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <string>

using namespace std;

#define MAX_SIZE 100
#define EMPTY -1

class Stack
{
    public:
    int values[MAX_SIZE - 1];
    int index = EMPTY;

    bool push(int value){
        if (index >= MAX_SIZE - 1)
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

    char topc(){
        return (char) top();
    }
};

int get_priority(char c){
    switch (c){
        case '(':
            return 4;
            break;
        case '+':
            return 3;
            break;
        case '-':
            return 3;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case ')':
            return 1;
            break;
    }

    return 0;
}

void cleanOperators(Stack* operators, string* postfix){
    while (!operators->isEmpty() && (operators->topc() != '(')){
        *postfix += operators->pop();
        *postfix += ' ';
    }
    if (!operators->isEmpty())
        operators->pop();
}

int main(int argc, char const *argv[])
{
    Stack operators;
    string line, postfix;

    // getline(cin, line);
    line = "5 * ( 3 * 6 + 2 ) + 10 + ( 14 / 3 + 4 )";
    for (size_t i=0; i<line.length(); i++){
        if (line[i] == ' ')
            continue;
        
        if (isdigit(line[i])){
            postfix += line[i];
            if(!isdigit(line[i+1]))
                postfix += ' '; 
        } else {
            if (!operators.isEmpty() && (get_priority(line[i]) >= get_priority(operators.topc()))){
                operators.push((int) line[i]);
            } else if (operators.isEmpty()){
                cout << "Empty stack" << endl;
                operators.push((int) line[i]);
            } else if (operators.topc() != '(') {
                cout << "Cleaning operators" << endl;
                cleanOperators(&operators, &postfix);
                if (line[i] != ')')
                    operators.push((int) line[i]);
            } else {
                operators.push((int) line[i]);
            }
        }
    }
    cleanOperators(&operators, &postfix);

    cout << "The result: " << postfix << endl;
    return 0;
}
