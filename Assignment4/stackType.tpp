//
//  stackType.cpp
//  stackApp
//
//  Created by Jose Ramon Santos on 9/23/23.
//

template <class Type>
const stackType<Type> &stackType<Type>::operator=(const stackType<Type> &otherStack)
{
    if (this != &otherStack) // avoid self-assignment
    {
        delete[] list;

        maxStackSize = otherStack.maxStackSize;
        stackTop = otherStack.stackTop;

        list = new Type[maxStackSize];
        for (int i = 0; i < stackTop; i++)
            list[i] = otherStack.list[i];
    }
    return *this;
}

template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
inline bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}

template <class Type>
inline bool stackType<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
}

template <class Type>
inline void stackType<Type>::push(const Type &newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;
        stackTop++;
    }
    else
    {
        std::cout << "Can not add to a full stack." << std::endl;
    }
}

template <class Type>
inline Type stackType<Type>::top() const
{
    if (!isEmptyStack())
    {
        return list[stackTop - 1];
    }
    else
    {
        throw std::underflow_error("Stack is empty, not top element.");
    }
}

template <class Type>
inline void stackType<Type>::pop()
{
    if (!isEmptyStack())
    {
        stackTop--;
    }
    else
    {

        throw std::underflow_error("Can not remove from a empty stack.");
    }
}

template <class Type>
inline stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        std::cout << "Size of the array to hold the stack must be positive" << std::endl;
        maxStackSize = 100;
    }
    else
    {
        maxStackSize = stackSize;
    }

    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
inline stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}

template <class Type>
inline stackType<Type>::~stackType()
{
    delete[] list;
}

template <class Type>
inline void stackType<Type>::copyStack(const stackType<Type> &otherStack)
{
    delete[] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new Type[maxStackSize];

    // stackTop holds the current number of elements
    for (int j = 0; j < stackTop; j++)
    {
        list[j] = otherStack.list[j];
    }
}
