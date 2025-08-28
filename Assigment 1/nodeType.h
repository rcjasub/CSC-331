template <class Type>
struct nodeType
{
   Type info; //holds the data
   nodeType<Type>* link; //pointer to the next node
};