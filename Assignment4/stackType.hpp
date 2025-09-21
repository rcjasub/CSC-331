//
//  stackType.hpp
//  stackApp
//
//  Created by Jose Ramon Santos on 9/23/23.
//

#ifndef stackType_hpp
#define stackType_hpp

#include <stdio.h>
#include <iostream>
#include "stackADT.hpp"
using namespace std;

template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&);
    //Overload the assignment operator.
    
    void initializeStack();
    //Function to insitialize the stack to an empty state.
    //Postcondition: stackTop = 0;
    
    bool isEmptyStack() const;
    //Function to determine whether the stack is empty.
    //Postcondition: Returns true if the stack is empty,
    //     otherwise returns false.
    
    bool isFullStack() const;
    //Function to determine whether the stack is full.
    //Postcondition: Returns true if the stack is full,
    //     otherwise returns false
    
    void push(const Type& newItem);
    //Function to add newItem to the stack.
    //Precondition:  The stack exists and is not full.
    //Postcondition: The stack is changed and newItem is
    //     added to the top fo the stack.
    
    Type top() const;
    //Function to return the top element of the stack.
    //Precondition:  The stack exists and is not empty
    //Postcondition: If the stack is empty the program
    //     terminates; otherwise, the top element of the stack
    //     is returned.
    
    void pop();
    //Function to remove the top element of the stack.
    //Precondition:  The stack exists and is not empty.
    //Postcondition: The stack is changed and the top element is
    //     removed from the stack.
    
    stackType(int stackSize = 100);
    //Constructor
    //Create an array of the size stackSize to hold
    //the stack elements.  The default stack size is 100.
    //Postcondition:  The variable list contains the base address
    //   of the array, stackTop = 0, and maxStackSize = stackSize
    
    stackType(const stackType<Type>& otherStack);
    //Copy constructor
    
    ~stackType();
    //Destructor
    //Remove all the elements from the stack.
    //Postcondition:  The array (list) holding the stack
    //   elements is deleted.
    
private:
    int maxStackSize;   //variable to store the maximum stack size
    int stackTop;       //variable to point to the top of the stack
    Type *list; //pointer to the array that holds the stack elements
    
    void copyStack(const stackType<Type>& otherStack);
    //Function to make a copy of otherStack
    //Postcondition:  A copy of otherStack is created and asssigned
    //   to this stack.
};

#endif /* stackType_hpp */

#include "stackType.tpp"