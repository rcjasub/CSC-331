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

};