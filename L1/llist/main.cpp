#include "../stack/stack.h"
#include "linkedList.h"
using namespace std;

bool isPalindrome(string text) {
    size_t length = text.length(), i = 0;
    Stack<char> firstHalf;

    for (i = 0; i < length / 2; i++)
        firstHalf.push(text[i]);

    if (length % 2)
        i++;

    while (i < length){
        if (firstHalf.pop() != text[i++])
            return false;
    }

    return true;
}

void testLinkedList(string line) {
    LinkedListNode generatedList = insertIntoLinkedList(line);
    string output = readLinkedList(generatedList);

    cout << line << ": " << (line == output ? "TEST PASSED" : "TEST FAILED") << endl;
}

void testPalindrome(string text, bool expected){
    cout << text << ": " << (isPalindrome(text) == expected ? "TEST PASSED" : "TEST FAILED") << endl;
}

int main(int argc, char const* argv[])
{
    testLinkedList("12203022");
    testLinkedList("3120213");
    testLinkedList("My character / sequence to insert into lined list, \\    hihi. 23");

    cout << "\n=============================\n\n";

    testPalindrome("12203022", false);
    testPalindrome("3120213", true);
    testPalindrome("My character / sequence to insert into lined list, \\    hihi. 23", false);
    // when entering non-ascii character like ś it's being counted as size 2 and fails the test
    testPalindrome("kamilślimak", true);
    testPalindrome("kamilslimak", true);

    return 0;
}
