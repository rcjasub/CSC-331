template <class type>
class linkedListIterator
{
public:

linkedListIterator();
//Default constructor
//postcondition: current is set to nullptr

linkedListIterator(nodeType<type>* ptr);
//Constructor with parameter
//Postcondition: current is set to ptr

type operator*();
//Function to overload the dereferencing operator *
//Postcondition: Returns the info contained in the node

linkedListIterator<type> operator++();
//Overload the pre-increment operator
//Postcondition: The iterator is advanced to the next node

bool operator==(const linkedListIterator<type>& right) const;
//Overload the equality operator
//Postcondition: Returns true if this iterator is equal to the right iterator, otherwise it returns false

bool operator!=(const linkedListIterator<type>& right) const;
//Overload the not equal to operator
//Postcondition: Returns true if this iterator is not equal to the right iterator, otherwise it returns false

private:
nodeType<type>* current; //pointer to point to the current node in the linked list

};


