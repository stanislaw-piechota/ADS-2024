#include "rpn.h"
using namespace std;

bool testConversion(string line, string expected) {
    return (infixToPostfix(line) == expected);
}

bool testParsing(string line, int expected) {
    return (parsePostfix(line) == expected);
}

int runTestCase(string infix, string postfix, int result, bool testForConv) {
    int correct = 1;
    cout << "\n============== " << (infix != "" ? infix : postfix) << " ==============" << endl;

    if (testForConv){
        if (testConversion(infix, postfix))
            cout << "CONVERSION SUCCESSFUL" << endl;
        else {
            cout << "EXPECTED CONVERSION RESULT IS DIFFERENT" << endl;
            cout << infixToPostfix(infix) << "    " << postfix << endl;
            correct = 0;
        }
    }

    try{
        if (testParsing(postfix, result))
            cout << "PARSING SUCCESSFUL" << endl;
        else {
            cout << "EXPECTED PARSING RESULT IS DIFFERENT" << endl;
            cout << parsePostfix(postfix) << "    " << result << endl;
            correct = 0;
        }
    } catch (int index){
        cout << "Postfix expression is incorrect" << endl;
    }

    cout << "==========================================\n";

    return correct;
}

int main(int argc, char const* argv[])
{
    // assuming the correctness of the input line

    // first obligatory test case
    runTestCase("17 * ( 2 + 3 ) + 4 + ( 8 * 5 )", "17 2 3 + 4 8 5 * + + *", 833, true);
    // second obligatory test case
    runTestCase("( 3 * 6 + 2 ) + ( 14 / 3 + 4 )", "3 6 2 + * 14 3 4 + / +", 26, true);
    // long expression, positive operands - negative result
    runTestCase("3 + 4 * 2 - 3 * ( 2 / 1 + 1 ) / ( 4 / 2 + 2 )", "3 4 + 2 3 - * 2 1 1 + / 4 2 2 + / / *", -7, true);
    // negative operands - negative result
    runTestCase("-2 * -7 + -7 / -2", "-2 -7 -7 + * -2 /", -14, true);
    // too much operators
    runTestCase("4 + 8 * 5 *", "4 8 + 5 * *", 44, true);
    // too much operands
    runTestCase("", "4 8 + 5 * 4", 44, false);
    return 0;
}
