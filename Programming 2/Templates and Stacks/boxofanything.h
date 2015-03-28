#ifndef BOXOFANYTHING_H
#define BOXOFANYTHING_H
#include <stdexcept>

template<class T>
class BoxOfAnything
{
public:
    BoxOfAnything(T value);
	
	//Precondition: has a value
	//Postcondition: none
	//Returns the value of the box
    T getValue();
	
	//Precondition: none
	//Postcondition: new value is set    
	void setValue(T value);
	
	//Precondition: has a previous
	//Postcondition: none
	//Returns previous box    
	BoxOfAnything<T>* getPrevious();
	
	//Precondition: none
	//Postcondition: new previous is set    
	void setPrevious(BoxOfAnything<T>* previous);
private:
    BoxOfAnything<T>* m_previous;
    T m_value;
};

#include "boxofanything.hpp"
#endif // BOXOFANYTHING_H
