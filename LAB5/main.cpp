#include "hashTableType.hpp"
#include <fstream>
#include<iostream>
using namespace std;

int main() {
    ifstream input("hashThis.txt");
    if (!input) {
        cout << "File failed to open!" << endl;
        return 1;
    }

    hashTableType<int> ht(10); // example size

    int num;
    while (input >> num)
        ht.insert(num);

    ht.print();
}
