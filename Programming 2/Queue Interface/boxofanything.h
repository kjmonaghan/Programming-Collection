#ifndef BOXOFANYTHING_H
#define BOXOFANYTHING_H
#include <stdexcept>

template<class T>
class BoxOfAnything
{
public:
    BoxOfAnything(T value);
    T getValue();
    void setValue(T value);
    BoxOfAnything<T>* getPrevious();
    void setPrevious(BoxOfAnything<T>* previous);
private:
    BoxOfAnything<T>* m_previous;
    T m_value;
};

#include "boxofanything.hpp"
#endif // BOXOFANYTHING_H
