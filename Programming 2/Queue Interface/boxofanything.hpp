#include "boxofanything.h"

template<class T>
BoxOfAnything<T>::BoxOfAnything(T value){
    m_value = value;
    m_previous = nullptr;
}

template<class T>
T BoxOfAnything<T>::getValue(){
    return m_value;
}

template<class T>
BoxOfAnything<T>* BoxOfAnything<T>::getPrevious(){
    return m_previous;
}

template<class T>
void BoxOfAnything<T>::setPrevious(BoxOfAnything<T> *previous){
    delete m_previous;
    m_previous = previous;
}

template<class T>
void BoxOfAnything<T>::setValue(T value){
    m_value = value;
}
