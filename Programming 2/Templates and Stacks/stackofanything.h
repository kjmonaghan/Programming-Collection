#ifndef STACKOFANYTHING_H
#define STACKOFANYTHING_H
#include "boxofanything.h"

template<class T>
class StackOfAnything
{
public:
    StackOfAnything();
    ~StackOfAnything();
	
	//Returns true if m_size = 0, returns false otherwise
    bool isEmpty() const;
	
	//Returns m_size    
	int size() const;
	
	//Postcondition: value is added to top of stack    
	void push(T value);
	
	//Precondition: Stack isn't empty
	//Returns top of stack
    T peek() const throw (std::runtime_error);
    
	//Precondition: Stack isn't empty
	//Postcondition: Top item on stack is removed
	//Returns: Top item on stack	
	T pop() throw (std::runtime_error);
private:
    BoxOfAnything<T>* m_top;
    int m_size;
};

#include "stackofanything.hpp"
#endif // STACKOFANYTHING_H
