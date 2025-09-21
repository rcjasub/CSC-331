#pragma once
#include "linkedListType.h"

template <class Type>
class orderedLinkList : public LinkListType<Type>
{
public:
    void insert(const Type &newItem);

    void insertFirst(const Type &newItem) override;
    void insertLast(const Type &newItem) override;
    void deleteNode(const Type &deleteItem) override;
    bool search(const Type &searchItem) const override;
};

#include "orderedLinkList.tpp"
