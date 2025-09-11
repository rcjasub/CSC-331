// #include <iostream>
// #include "unorderedLinkedList.h"
// using namespace std;

// int main() {
//     unorderedLinkedList<int> list;

//     list.insertFirst(10);
//     list.insertLast(20);
//     list.insertFirst(5);

//     cout << "List: ";
//     list.print();  // Expected: 5 -> 10 -> 20

//     cout << "Head: " << list.getHead() << endl;   // 5
//     cout << "Tail: " << list.getTail() << endl;   // 20
//     cout << "Length: " << list.getLength() << endl; // 3

//     cout << "Search 10? " << (list.search(10) ? "Yes" : "No") << endl;
//     cout << "Search 99? " << (list.search(99) ? "Yes" : "No") << endl;

//     list.deleteNode(10);
//     cout << "After deleting 10: ";
//     list.print();  // Expected: 5 -> 20

//     return 0;
// }
