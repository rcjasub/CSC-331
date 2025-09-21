#include <iostream>
#include "unorderedLinkedList.h"

template <class Type>
inline bool unorderedLinkedList<Type>::search(const Type &searchItem) const
{
    nodeType<Type> *current = this->head;

    while (current != nullptr)
    {
        if (current->value == searchItem)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

template <class Type>
inline void unorderedLinkedList<Type>::insertFirst(const Type &newItem)
{
    nodeType<Type> *newNode = new nodeType<Type>(newItem);

    if (this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->next = this->head;
        this->head = newNode;
    }

    this->count++;
}

template <class Type>
inline void unorderedLinkedList<Type>::insertLast(const Type &newItem)
{
    nodeType<Type> *newNode = new nodeType<Type>(newItem);

    if (this->head == nullptr)
    {
        this->head = this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }

    this->count++;
}

template <class Type>
inline void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    nodeType<Type> *curr = this->head;
    nodeType<Type> *prev = nullptr;

    if (this->head == nullptr)
        return;

    while (curr != nullptr)
    {
        if (curr->value == deleteItem)
        {
            nodeType<Type> *temp = curr->next;

            if (curr == this->head)
            {
                this->head = curr->next;
                if (curr == this->tail)
                {
                    this->tail = nullptr;   
                }
            }
            else
            {
                prev->next = curr->next;
                if (curr == this->tail)
                {
                    this->tail = prev;
                }
            }

            delete curr;
            this->count--;
            curr = temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}
