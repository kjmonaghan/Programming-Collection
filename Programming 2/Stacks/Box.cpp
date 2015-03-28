#include "Box.h"

Box::Box(){
	this->m_value = 0;
	this->m_previous = nullptr;
}

int Box::getValue(){
	return (this->m_value);
}

void Box::setValue(int val){
	this->m_value = val;
}

Box* Box::getPrevious(){
	return this->m_previous;
}

void Box::setPrevious(Box* prev){
	this->m_previous = prev;
}

