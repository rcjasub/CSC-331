#pragma once
template <class Type>
struct nodeType
{
   Type value; //holds the data
   nodeType<Type>* next; //pointer to the next node
};