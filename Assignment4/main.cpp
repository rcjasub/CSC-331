//
//  main.cpp
//  stackApp
//
//  Created by Jose Ramon Santos on 9/23/23.
//  Implementation of stack as an array

#include <iostream>
#include "stackType.hpp"
void testCopyConstructor(stackType<int> otherStack);
int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "This program will use a stack using stackADT class!\n";

    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);

    stack.initializeStack();
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);

    copyStack = stack;

    cout << "The elements of copyStack: ";

    while (!copyStack.isEmptyStack()) // print copyStack
    {
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;

    copyStack = stack;
    testCopyConstructor(stack); // test the copy constructor

    if (!stack.isEmptyStack())
        cout << "The original stack is not empty." << endl
             << "The top element of the original stack: "
             << copyStack.top() << endl;

    dummyStack = stack; // copy stack into dummyStack

    cout << "The elements of dummyStack: ";

    while (!dummyStack.isEmptyStack())
    {
        cout << dummyStack.top() << " ";
        dummyStack.pop();
    }
    cout << endl;

    std::cout << "Submitted by Jocsan Rodriguez" << std::endl;

    return 0;
}

void testCopyConstructor(stackType<int> otherStack)
{
    if (!otherStack.isEmptyStack())
        cout << "otherStack is not empty." << endl
             << "The top element of otherStack: "
             << otherStack.top() << endl;
}
