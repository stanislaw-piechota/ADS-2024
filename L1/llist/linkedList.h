#include <iostream>

class LinkedListNode {
public:
    char value;
    LinkedListNode* next = nullptr;
};

LinkedListNode insertIntoLinkedList(std::string text);
std::string readLinkedList(LinkedListNode list);