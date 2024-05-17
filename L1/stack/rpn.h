#ifndef __RPN__
#include "stack.h"
#include <iostream>

int getPriority(char c);
void cleanOperators(Stack<char>* operators, std::string* postfix);
void processSign(Stack<char> *operators, std::string *postfix, char sign);
void executeOperation(Stack<int> *operands, char operation);
std::string infixToPostfix(std::string line);
int parsePostfix(std::string postfix);

#endif