#include <iostream>
#include "linkedListType.h"
#include <cassert>
using namespace std;

template <class Type>
linkedListIterator<Type> LinkListType<Type>::begin()
{
    linkedListIterator<Type> temp(head);
    return temp;
}

template <class Type>
linkedListIterator<Type> LinkListType<Type>::end()
{
    linkedListIterator<Type> temp(nullptr);
    return temp;
}

template <class Type>
LinkListType<Type>::LinkListType()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class Type>
LinkListType<Type>::LinkListType(const LinkListType<Type> &otherList)
{
    head = nullptr;
    copyList(otherList);
}

template <class Type>
LinkListType<Type>::~LinkListType()
{
    destroyList(); // free memory when the object goes out of scope
}

template <class Type>
void LinkListType<Type>::copyList(const LinkListType<Type> &otherList)
{
    nodeType<Type> *newNode; // pointer to create a node
    nodeType<Type> *current; // pointer to traverse the list

    if (head != nullptr)
    {
        destroyList(); // if the list is non-empty, make it empty
    }

    if (otherList.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.head; // current points to the list to be copied
        count = otherList.count;

        head = new nodeType<Type>;    // create the head node
        head->value = current->value; // copy the value
        head->next = nullptr;         // set the next of head to nullptr
        tail = head;                  // tail points to the last node in the list
        current = current->next;      // advance current to the next node

        while (current != nullptr)
        {
            newNode = new nodeType<Type>;    // create a new node
            newNode->value = current->value; // copy the value
            newNode->next = nullptr;         // set the next of newNode to nullptr
            tail->next = newNode;            // attach newNode after tail
            tail = newNode;                  // update tail to point to the last node
            current = current->next;         // advance current to the next node
        }
    }
}

template <class Type>
const LinkListType<Type> &LinkListType<Type>::operator=(const LinkListType<Type> &other)
{
    if (this != &other)
    {
        copyList(other);
    }
    return *this;
}

template <class Type>
void LinkListType<Type>::initializeList()
{
    destroyList(); // destroy the existing list
}

template <class Type>
bool LinkListType<Type>::isEmptyList() const
{
    return (head == nullptr); // true
}

template <class Type>
void LinkListType<Type>::print() const
{
    nodeType<Type> *temp = head;
    if (temp == nullptr)
    {
        cout << "empty list" << endl;
        return;
    }

    // traverse the list
    while (temp != nullptr)
    {
        cout << temp->value;
        temp = temp->next; // move to the next node
        if (temp != nullptr)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}

template <class Type>
int LinkListType<Type>::getLength() const
{
    return count;
}

template <class Type>
void LinkListType<Type>::destroyList()
{
    nodeType<Type> *temp; // pointer to deallocate the memory occupied by the node
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp; // deletes the old head, repeats until the head is nullptr
    }

    // reset the member variables
    tail = nullptr;
    length = 0;
}

template <class Type>
Type LinkListType<Type>::getHead() const
{
    return head->value;
}

template <class Type>
Type LinkListType<Type>::getTail() const
{
    return tail->value;
}
