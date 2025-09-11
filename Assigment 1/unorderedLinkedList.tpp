// #include "unorderedLinkedList.h"

// template <class Type>
// bool unorderedLinkedList<Type>::search(const Type &searchItem) const
// {
//     auto current = this->head;
//     while (current != nullptr)
//     {
//         if (current->value == searchItem)
//             return true;
//         current = current->next;
//     }
//     return false;
// }

// template <class Type>
// void unorderedLinkedList<Type>::insertFirst(const Type &newItem)
// {
//     nodeType<Type> *newNode = new nodeType<Type>;
//     newNode->value = newItem;
//     newNode->next = this->head;
//     this->head = newNode;
//     if (this->tail == nullptr)
//         this->tail = newNode;
//     this->count++;
// }

// template <class Type>
// void unorderedLinkedList<Type>::insertLast(const Type &newItem)
// {
//     nodeType<Type> *newNode = new nodeType<Type>;
//     newNode->value = newItem;
//     newNode->next = nullptr;
//     if (this->head == nullptr)
//     {
//         this->head = this->tail = newNode;
//     }
//     else
//     {
//         this->tail->next = newNode;
//         this->tail = newNode;
//     }
//     this->count++;
// }

// template <class Type>
// void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem)
// {
//     if (this->head == nullptr)
//         return;

//     if (this->head->value == deleteItem)
//     {
//         nodeType<Type> *temp = this->head;
//         this->head = this->head->next;
//         delete temp;
//         this->count--;
//         if (this->head == nullptr)
//             this->tail = nullptr;
//         return;
//     }

//     auto current = this->head;
//     while (current->next != nullptr && current->next->value != deleteItem)
//     {
//         current = current->next;
//     }

//     if (current->next != nullptr)
//     {
//         nodeType<Type> *temp = current->next;
//         current->next = temp->next;
//         if (temp == this->tail)
//             this->tail = current;
//         delete temp;
//         this->count--;
//     }
// }