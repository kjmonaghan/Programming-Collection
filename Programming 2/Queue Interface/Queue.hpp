//Queue.hpp
//Keith Monaghan
//9-28-14

#include "Queue.h"
#include "boxofanything.h"
#include "PreconditionViolationException.h"
#include <iostream>

template<class T>
void Queue<T>::enqueue(const T newEntry){
	if(isEmpty()){
		m_back = new BoxOfAnything<T>(newEntry);
		m_front = m_back;
	}
	else{
		m_back->setPrevious(new BoxOfAnything<T>(newEntry));
		m_back = m_back->getPrevious();
	}

	m_size++;
}

template<class T>
T Queue<T>::dequeue() throw(PreconditionViolationException){
	if(isEmpty())
		throw PreconditionViolationException("Dequeue attempted on an empty Queue");

	T value = m_front->getValue();
	BoxOfAnything<T>* temp = m_front;

	if(m_front == m_back){
		m_front = nullptr;
		m_back = nullptr;
	}
	else
		m_front = m_front->getPrevious();

	delete temp;
	temp = nullptr;

	m_size--;

	return value;
}

template<class T>
T Queue<T>::peekFront() const throw(PreconditionViolationException){
	if(isEmpty())
		throw PreconditionViolationException("Peek attempted on an empty Queue");

	return m_front->getValue();
}

template<class T>
void Queue<T>::print() const{
	BoxOfAnything<T>* temp = m_front;
	while(temp->getPrevious() != nullptr){
		std::cout << temp->getValue() << ',';
		temp = temp->getPrevious();
	}

	std::cout << temp->getValue() << std::endl;

	temp = nullptr;
}

template<class T>
Queue<T>::~Queue(){
	while(!isEmpty())
		dequeue();
}

template<class T>
bool Queue<T>::operator< (const QueueInterface<T>& rhs) const{ return (this->size() < rhs.size()); }

template<class T>
bool Queue<T>::operator<= (const QueueInterface<T>& rhs) const{ return (this->size() <= rhs.size()); }

template<class T>
bool Queue<T>::operator> (const QueueInterface<T>& rhs) const{ return (this->size() > rhs.size()); }

template<class T>
bool Queue<T>::operator>= (const QueueInterface<T>& rhs) const{ return (this->size() >= rhs.size()); }

template<class T>
bool Queue<T>::operator== (const QueueInterface<T>& rhs) const{ return (this->size() == rhs.size()); }

template<class T>
bool Queue<T>::operator!= (const QueueInterface<T>& rhs) const{ return (this->size() != rhs.size()); }