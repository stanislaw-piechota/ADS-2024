#include "linkedList.h"

LinkedListNode insertIntoLinkedList(std::string text) {
    LinkedListNode list;
    LinkedListNode* currentNode = &list;
    size_t i;

    for (i = 0; i < text.length() - 1; i++) {
        currentNode->value = text[i];
        currentNode->next = new LinkedListNode;
        currentNode = currentNode->next;
    }
    currentNode->value = text[i];

    return list;
}

std::string readLinkedList(LinkedListNode list) {
    LinkedListNode* currentNode = &list;
    std::string output = "";

    while (currentNode->next) {
        output += currentNode->value;
        currentNode = currentNode->next;
    }
    output += currentNode->value;

    return output;
}