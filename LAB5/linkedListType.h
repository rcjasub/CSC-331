//
//  linkedListType.hpp
//  linkedListApp
//
//  Created by Jose R Santos on 9/9/23.
//

#ifndef linkedListType_hpp
#define linkedListType_hpp

#include <stdio.h>
#include <iostream>
#include "string.h"
#include "nodeType.h"
#include "linkedListIterator.h"

using namespace std;

template <class Type>
class linkedListType
{
public:
    //Definition of the node

    const linkedListType<Type>& operator= (const linkedListType<Type>&);  // Overload the assignment operator.
    void initializeList();  // Initialize list to an empty state.
                            // Postcondition:  first = NULL, last = NULL, count = 0;
    bool isEmptyList() const;   //Function to determine whether the list is empty
                                //Postcondition:  Returns true if the list is empty, otherwise it returns false
    void print() const;

    int length() const;

    void destroyList();

    Type front() const;

    Type back() const;

    virtual bool search(const Type& searchItem) const = 0;
    //Function to determine whether searchItem is in the list
    //Postcondition: Returns true if searchItem is in the list,
    //  otherwise the value false is returned

    virtual void insertFirst(const Type& newItem) = 0;
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, last points to
    // the last node in the list, and count is incremented by 1.

    virtual void insertLast(const Type& newItem) = 0;
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    //  inserted at the end of the list, last points to the
    //  last node in the list, and count is incremented by 1.

    virtual void deleteNode(const Type& deleteItem) = 0;
    //Function to delete deleteItem from the list.
    //Postcondition:  If found, the node containing deleteItem is
    //  deleted from the list.  first points to the first node,
    //  last points to the last node of the updated list, and
    //  count is decremented by 1

    linkedListIterator<Type> begin();
    //Function to return an iterator at the beginning of the linked list.
    //Postcondition:  Returns an iterator such that current is set to first.

    linkedListIterator<Type> end();
    //Function to return an iterator one element past the last element of the linked list.
    //Postcondition:  Returns an iterator such that current is set to NULL.

    linkedListType();
    //default constructor
    //Initializes the list to an empty space.
    //Postcondition: first = NULL, last = NULL, count = 0;

    linkedListType(const linkedListType<Type>& otherList);
    //copy constructor

    ~linkedListType();
    //destructor
    //Deletes all the nodes from the list.
    //Postcondition:  The list object is destroyed


protected:
    int count;    //variable to store the number of list elements
    nodeType<Type>* first;    //pointer to the first node of the list
    nodeType<Type>* last;    //pointer to the last node of the list

private:
    void copyList(const linkedListType<Type>& otherList);
    //Function to make a copy of otherList.
    //Postcondition:  A copy of otherList is created and assigned to this list
};

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == NULL);
};

template <class Type>
linkedListType<Type>::linkedListType()    //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
};

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type>* temp;        //pointer to deallocate the memory
                                //occupied by the node
    while (first != NULL)        //while there are nodes in the list
    {
        temp = first;            //set temp to the current node
        first = first->link;    //advance first to the next node
        delete temp;            //deallocate the memory occupied by temp
    }
    last = NULL;                //initialize the last to NULL
    count = 0;                    //first has already been set to NULL by the loop

};

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();    //if the list has any nodes, delete them
};

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type>* current;    //pointer to traverse the list
    current = first;            //set the current point to the first node
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
} //end print

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);
    return first->info; //return the info of the first node
}

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);
    return last->info;  //return the info of the last node
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);

    return temp;
}
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);

    return temp;
}

//To continue here.  pg 289, 2nd Edition, Malik.
//Copy the list code
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
    nodeType<Type>* newNode;    //pointer to create a node
    nodeType<Type>* current;    //pointer to traverse the list
    if (first != NULL)  //if th elist is nonempty, make it empty
        destroyList();
    if (otherList.first == NULL)    //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first;  //current points to the list to be copied
        count = otherList.count;
        //copy the first node
        first = new nodeType<Type>;     //create the node
        first->info = current->info;    //copy the info
        first->link = NULL;             //set the linke field of the node to NULL
        last = first;                   //make last point to the first node
        current = current->link;        //make current point ot the next node

            //copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>;   //create a node
            newNode->info = current->info;  //copy the info
            newNode->link = NULL;           //set the link of newNode to NULL
            last->link = newNode;           //attach newNode after the last
            last = newNode;                 //make last point to the actual last node
            current = current->link;        //make current point to the next node
        }//end while
    }//end else
}    //end copyList


template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    //copy constructor
    first = NULL;
    copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
    if (this != &otherList)     //avoid self-copy
    {
        copyList(otherList);
    }//end else

    return *this;
}


#endif /* linkedListType_hpp */
