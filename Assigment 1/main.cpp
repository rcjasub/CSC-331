// Created by Jocsan Rodriguez

#include <iostream>
#include "unorderedLinkedList.h"
using namespace std;

int main()
{
    unorderedLinkedList<double> list;

    list.insertFirst(10);
    list.insertLast(20);
    list.insertFirst(5);
    list.insertLast(25);
    list.insertFirst(1.64);
    list.insertLast(30);
    list.insertFirst(0.34);
    list.insertLast(35);
    list.insertFirst(5);
    list.insertLast(30);

    cout << "List: ";
    list.print();

    cout << "Head: " << list.getHead() << endl;
    cout << "Tail: " << list.getTail() << endl;
    cout << "Length: " << list.getLength() << endl;

    cout << "is 10 in the list? " << (list.search(10) ? "Yes" : "No") << endl;
    cout << "is 99 in the list? " << (list.search(99) ? "Yes" : "No") << endl;

    list.deleteNode(10);
    list.deleteNode(5);
    list.deleteNode(30);
    cout << "After deleting some nodes: ";
    list.print();

    double total = 0.0;
    double subtotal = 0.0;

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        total += *it;                      // full value
        subtotal += static_cast<int>(*it); // integer part only
    }

    cout << "Total: $" << total << endl;
    cout << "SubTotal: $" << subtotal << endl;
    cout << "Submitted by: Jocsan Rodriguez" << endl;

    return 0;
}
