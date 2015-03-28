#include "stackofanything.h"
#include "boxofanything.h"
#include <stdexcept>
#include <iostream>

template<class T>
StackOfAnything<T>::StackOfAnything()
{
    m_top = nullptr;
    m_size = 0;
}

template<class T>
StackOfAnything<T>::~StackOfAnything(){
    while(m_size != 0){
        this->pop();
    }
}

template<class T>
bool StackOfAnything<T>::isEmpty() const{
    return (m_size == 0);
}

template<class T>
int StackOfAnything<T>::size() const{
    return m_size;
}

template<class T>
void StackOfAnything<T>::push(T value){
    BoxOfAnything<T>* newTop = new BoxOfAnything<T>(value);
    newTop->setPrevious(m_top);
    m_top = newTop;

    m_size++;
}

template<class T>
T StackOfAnything<T>::peek() const throw(std::runtime_error){
    if(this->isEmpty()){
	throw std::runtime_error("Peek attempted on empty stack");
    }
    else{
      return m_top->getValue();
    }
}

template<class T>
T StackOfAnything<T>::pop() throw(std::runtime_error){
    if(this->isEmpty())
      throw std::runtime_error("Pop attempted on empty stack");
    else{
      BoxOfAnything<T>* temp = m_top->getPrevious();
      T value = m_top->getValue();

      delete m_top;
      m_top = temp;

      m_size--;
      return value;
    }
}
