#include "rpn.h"

int getPriority(char c){
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

void cleanOperators(Stack<char>* operators, std::string* postfix){
    while (!operators->isEmpty() && (operators->top() != '(')){
        *postfix += operators->pop();
        *postfix += ' ';
    }
    if (!operators->isEmpty())
        operators->pop();
}

void processSign(Stack<char> *operators, std::string *postfix, char sign){
    if (!operators->isEmpty() && (getPriority(sign) >= getPriority(operators->top())))
        operators->push(sign);
    else if (operators->isEmpty())
        operators->push(sign);
    else if (operators->top() != '(') {
        cleanOperators(operators, postfix);
        if (sign != ')')
            operators->push(sign);
    } else {
        operators->push(sign);
    }
}

void executeOperation(Stack<int> *operands, char operation){
    int prevNumber = operands->pop();
    switch(operation){
        case '+':
            operands->push(operands->pop() + prevNumber);
            break;
        case '-':
            operands->push(operands->pop() - prevNumber);
            break;
        case '*':
            operands->push(operands->pop() * prevNumber);
            break;
        case '/':
            operands->push(operands->pop() / prevNumber);
            break;
    }
}

std::string infixToPostfix(std::string line){
    Stack<char> operators;
    std::string postfix;

    for (size_t i=0; i<line.length(); i++){
        if (line[i] == ' ')
            continue;
        if ((line[i] == '-') && isdigit(line[i+1])){
            postfix += '-';
            continue;
        }
        
        if (isdigit(line[i])){
            postfix += line[i];
            if(!isdigit(line[i+1]))
                postfix += ' '; 
        } else
            processSign(&operators, &postfix, line[i]);
    }
    cleanOperators(&operators, &postfix);

    // remove last space from the string
    return postfix.substr(0, postfix.length()-1);
}

int parsePostfix(std::string postfix){
    Stack<int> operands;
    int number = 0, sign = 1;

    for (size_t i=0; i<postfix.length(); i++){
        if (postfix[i] == ' '){
            if (number){
                operands.push(number * sign);
                number = 0;
                sign = 1;
            }
            continue;
        }
        if ((postfix[i] == '-') && isdigit(postfix[i+1])){
            sign = -1;
            continue;
        }
        
        if (isdigit(postfix[i]))
            number = number * 10 + postfix[i] - '0';
        else 
            executeOperation(&operands, postfix[i]);
    }

    assert(!operands.index);
    return operands.pop();
}