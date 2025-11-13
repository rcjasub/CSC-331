//
//  unorderedLinkedList.hpp
//  linkedListApp
//
//  Created by Jose R Santos on 9/9/23.
//

#ifndef unorderedLinkedList_hpp
#define unorderedLinkedList_hpp
// #include "nodeType.h"
#include "linkedListType.h"
#include <stdio.h>
#include <iostream>
#include "string.h"
// using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list

    void insertFirst(const Type& newItem);
    //Function to insert newItem at the beginning of the list

    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list

    void deleteNode(const Type& deleteItem);
    //Function to delete deleteItem from the list
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    //search searchItem
    nodeType<Type>* current;    //pointer to traverse the list
    bool found = false;

    current = linkedListType<Type>::first;    //set current to point to the first node in the list

    while (current != NULL && !found)   //search the list
        if (current->info == searchItem)
            found = true;
        else
            current = current->link;    //make current point to the next node

    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    //Insert the first node
    nodeType<Type>* newNode;    //pointer to create the new node

    newNode = new nodeType<Type>;   //create the new node
    newNode->info = newItem;
    newNode->link = linkedListType<Type>::first;     //insert newNode before first
    linkedListType<Type>::first = newNode;    //make first point to the actual first node
    linkedListType<Type>::count++;

    if (linkedListType<Type>::last == NULL)
        linkedListType<Type>::last = newNode;     //if the list was empty, newNode is also the last node in the list

}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type>* newNode;    //pointer to create thenew node
    newNode = new nodeType<Type>;   //create the new node
    newNode->info = newItem;
    newNode->link = NULL;       //set the link field of newNode to NULL

    if (linkedListType<Type>::first == NULL)
    {
        linkedListType<Type>::first = newNode;        //if the list is empty, newNode is both the first and last node
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;
    }
    else
    {
        linkedListType<Type>::last->link = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;
    }
}//end insertLast

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current;    //pointer to traverse the list
    nodeType<Type>* trailCurrent;   //pointer just before current
    bool found;

    if (linkedListType<Type>::first == NULL)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        if (linkedListType<Type>::first->info == deleteItem) //Case 2
        {
            current = linkedListType<Type>::first;
            linkedListType<Type>::first = linkedListType<Type>::first->link;
            linkedListType<Type>::count--;

            if (linkedListType<Type>::first == NULL)
                linkedListType<Type>::last = NULL;

            delete current;
        }
        else
        {
            found = false;
            trailCurrent = linkedListType<Type>::first;   //set trailCurrent to point to the frist node
            current = linkedListType<Type>::first->link;  //set current to point to the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                linkedListType<Type>::count--;

                if (linkedListType<Type>::last == current)    //node to be deleted was the last node
                    linkedListType<Type>::last = trailCurrent;    //update the value of last
                delete current;
            }
            else
                cout << "The item to be deleted is not in the list." << endl;
        }//end else
    }//end else
}//end deleteNode


#endif /* unorderedLinkedList_hpp */
