#include<iostream>
#include"arrayListType.h"
using namespace std;

int main() {

    arrayListType<int> list1(100);
    arrayListType<double> list2(100);

    list1.insertEnd(10);
    list1.insertEnd(20);
    list1.insertEnd(30);

    list1.isEmpty() ? cout << "List 1 is empty." << endl : cout << "List 1 is not empty." << endl;
    list1.listSize() ? cout << "List 1 size: " << list1.listSize() << endl : cout << "List 1 is empty." << endl;
    // list1.retrieveAt(1, *(new int));
    list1.replaceAt(1, 25);

    list2.insertEnd(11.5);
    list2.insertEnd(23.2);
 
    cout << "List 1 elements: ";
    list1.print();
    cout << "List 2 elements: ";
    list2.print();

    return 0;
};