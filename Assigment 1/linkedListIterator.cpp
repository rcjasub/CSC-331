#include <iostream>
#include "linkedListIterator.h"

using namespace std;

template <class type>
inline linkedListIterator<type>::linkedListIterator()
{
    current = nullptr; 
}

template <class type>
linkedListIterator<type>::linkedListIterator(nodeType<type> *ptr)
{
    current = ptr;
}

template <class type>
type linkedListIterator<type>::operator*()
{
    return current->info;
}

template <class type>
linkedListIterator<type> linkedListIterator<type>::operator++()
{
    current = current->link; //link is a pointer to the next node
    return *this;
    //get the next node
}

template <class type>
bool linkedListIterator<type>::operator==(const linkedListIterator<type> &right) const
{
    return (current == right.current);
}

template <class type>
bool linkedListIterator<type>::operator!=(const linkedListIterator<type> &right) const
{
    return (current != right.current);
}
