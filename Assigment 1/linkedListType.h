#pragma once
#include "nodeType.h"
#include "linkedListIterator.h"

template <class Type>
class LinkListType
{
public:
    const LinkListType<Type> &operator=(const LinkListType<Type> &other);
    // Overload the assignment operator

    void initializeList();
    // Initialize the list to an empty state
    // Postcondition: first = nullptr, last = nullptr, length = 0

    bool isEmptyList() const;
    // Function to determine whether the list is empty
    // Postcondition: Returns true if the list is empty, otherwise it returns false

    void print() const;
    // Function to output the data contained in each node
    // Postcondition: none

    int getLength() const;
    // Function to return the number of nodes in the list

    void destroyList();
    // Function to delete all the nodes from the list

    Type getHead() const;
    // Function to return the first element of the list
    // Precondition: The list must exist and must not be empty

    Type getTail() const;
    // Function to return the last element of the list
    // Precondition: The list must exist and must not be empty

    // Reminder for me:
    // Virtual = “Allow overriding + call the correct version via base pointer/reference.”

    virtual bool search(const Type &searchItem) const = 0;
    // Function to determine whether searchItem is in the list

    virtual void insertFirst(const Type &newItem) = 0;
    // Function to insert newItem at the beginning of the list

    virtual void insertLast(const Type &newItem) = 0;
    // Function to insert newItem at the end of the list

    virtual void deleteNode(const Type &deleteItem) = 0;
    // Function to delete deleteItem from the list

    linkedListIterator<Type> begin();
    // Function to return an iterator at the beginning of the linked list
    // Postcondition: current is set to first

    linkedListIterator<Type> end();
    // Function to return an iterator at the end of the linked list
    // Postcondition: current is set to nullptr

    LinkListType();
    // Default constructor
    // initializes the list to an empty state
    // Postcondition: first = nullptr, last = nullptr, length = 0

    LinkListType(const LinkListType<Type> &otherList);
    // Copy constructor

    ~LinkListType();
    // Destructor

protected:
    int count;            // variable to store the number of nodes in the list
    nodeType<Type> *head; // pointer to the first node of the list
    nodeType<Type> *tail; // pointer to the last node of the list

private:
    void copyList(const LinkListType<Type> &otherList);
    // Function to make a copy of otherList
};

#include "linkedListType.tpp"

