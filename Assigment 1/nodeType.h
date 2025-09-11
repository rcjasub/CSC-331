#pragma once
template <class Type>
struct nodeType
{
   Type value;
   nodeType<Type> *next;

   nodeType() : next(nullptr) {}                               // default constructor
   nodeType(const Type &value) : value(value), next(nullptr) {} // value constructor
};
