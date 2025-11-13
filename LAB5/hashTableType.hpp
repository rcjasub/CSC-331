#pragma once
#include<iostream>
using namespace std;
template <class elemType>
class hashTableType {
private:
    struct Node {
        elemType data;
        Node* next;
    };

    Node** table;  // array of linked list heads
    int HTSize;

public:
    hashTableType(int size = 10) {
        HTSize = size;
        table = new Node*[HTSize];
        for (int i = 0; i < HTSize; i++)
            table[i] = nullptr;
    }

    int hash(const elemType& key) {
        return key % HTSize; // adjust for your record type
    }

    void insert(const elemType& key) {
        int index = hash(key);
        Node* newNode = new Node{key, nullptr};

        if (table[index] == nullptr)
            table[index] = newNode;
        else {
            Node* curr = table[index];
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = newNode;
        }
    }

    void print() const {
        for (int i = 0; i < HTSize; i++) {
            cout << "Index " << i << ": ";
            Node* curr = table[i];
            while (curr != nullptr) {
                cout << curr->data;
                if (curr->next != nullptr) cout << " -> ";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    ~hashTableType() {
        for (int i = 0; i < HTSize; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }
};
