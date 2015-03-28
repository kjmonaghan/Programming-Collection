#include "StackOfBoxes.h"
#include "Box.h"

StackOfBoxes::StackOfBoxes(){
	m_top = nullptr;
	m_size = 0;
}

StackOfBoxes::~StackOfBoxes(){
	while(!isEmpty())
		this->pop();	
}

bool StackOfBoxes::isEmpty() const{
	if(m_size == 0)
		return true;
	else
		return false;
}

int StackOfBoxes::size() const{
	return this->m_size;
}

void StackOfBoxes::push(int value){
	Box* newTop = new Box();
	newTop->setValue(value);
	
	newTop->setPrevious(this->m_top);
	m_top = newTop;
	
	m_size++;
}

int StackOfBoxes::pop(){
	if(!this->isEmpty()){
		Box* newTop = m_top->getPrevious();
		int value = m_top->getValue();
		
		delete m_top;
		m_top = newTop;
		
		m_size--;
		return value;
	}
	else
		return 0;
}
