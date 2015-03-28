//stackofanything.h
//Keith Monaghan
//9-30-14

#ifndef STACKOFANYTHING_H
#define STACKOFANYTHING_H
#include "boxofanything.h"

template<class T>
class StackOfAnything
{
public:
	//Constructor
    StackOfAnything();
    
    //Destructor
    ~StackOfAnything();
    
    //Returns true if the stack has 0 elements
    bool isEmpty() const;
    
    //Returns the number of elements in the stack
    int size() const;
    
    //Adds value to the top of the stack
    void push(T value);
    
    //Returns the top element of the stack without removing it
    //Precondition:  The stack cannot be empty
    T peek() const throw (std::runtime_error);
    
    //Removes the top element from the stack and returns it
    //Precondition:  The stack cannot be empty
    T pop() throw (std::runtime_error);
private:

	//Member variables
    BoxOfAnything<T>* m_top;
    int m_size;
};

#include "stackofanything.hpp"
#endif // STACKOFANYTHING_H
