#include <iostream>
#include "arrayListType.h"
using namespace std;

int main()
{
    // Create integer and double lists
    arrayListType<int> list1(10);
    arrayListType<double> list2(3);

    // Insert elements into list1
    list1.insertEnd(10);
    list1.insertEnd(20);
    list1.insertEnd(30);

    // Display list1 elements and size
    cout << "List 1 elements: ";
    list1.print();
    if (list1.listSize())
        cout << "List 1 size: " << list1.listSize() << endl;
    else
        cout << "List 1 is empty." << endl;

    // Modify list1
    list1.replaceAt(1, 25);
    list1.remove(10);

    // Insert elements into list2 (last insert should show error)
    list2.insertEnd(11.5);
    list2.insertEnd(23.2);
    list2.insertEnd(34.8);

    cout << "List 2 elements: ";
    list2.print();

    list2.insertEnd(45.6); // Should show error: list is full
    list2.isFull() ? cout << "List 2 is full." << endl : cout << "List 2 is not full." << endl;

    // Display list1 after modifications
    cout << "List 1 elements after modifying: ";
    list1.print();

    // Clear list1 and display
    list1.clearList();
    cout << "List 1 elements after clearing: ";
    list1.print();
    if (list1.listSize())
    {
        cout << "List 1 size: " << list1.listSize() << endl;
    }
    else
    {
        cout << "List 1 is empty." << endl;
    }

    cout << "List 2 size: " << list2.listSize() << endl;

    list2.removeAt(1); // Remove element at index 1
    // Display list2 elements
    cout << "New List 2 elements: ";
    list2.print();

    return 0;
};