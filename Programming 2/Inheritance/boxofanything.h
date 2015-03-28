//boxofanything.h
//Keith Monaghan
//9-30-14

#ifndef BOXOFANYTHING_H
#define BOXOFANYTHING_H
#include <stdexcept>

template<class T>
class BoxOfAnything
{
public:
	//Constructor
    BoxOfAnything(T value);
    
    //Returns the value contained in the box
    T getValue();
    
    //Sets the value of the box to the given T
    void setValue(T value);
    
    //Returns the pointer of the previous box
    BoxOfAnything<T>* getPrevious();
    void setPrevious(BoxOfAnything<T>* previous);
private:

	//Member variables
    BoxOfAnything<T>* m_previous;
    T m_value;
};

#include "boxofanything.hpp"
#endif // BOXOFANYTHING_H
