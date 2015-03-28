#include <iostream>
#include "StackOfBoxes.h"

int main() {
	StackOfBoxes stack;	//Create an empty stack allocated stack
	StackOfBoxes* stackPtr = new StackOfBoxes(); //Create a heap allocated stack

	int sizeOfStack;	//int we'll use later to store the size of the stack
	
	//push some numbers onto the stack
	for(int i = 1; i <= 10; i++)
	{
		stack.push( i * 5 );
		stackPtr->push( i * 5 );
	}


	//Store the size of the stack before popping anything
	sizeOfStack = stack.size();	

	std::cout << "There are " << sizeOfStack << " items on the stack" << std::endl;

	//Think about why we don't use i<stack.size()
	for(int i = 0; i < sizeOfStack; i++)
	{
		std::cout << "Popping the top: " << stack.pop() << std::endl;
		//We won't pop anything from stackPtr
	}
	
	//Deleting a pointer calls the destructor for the object it points to
	delete stackPtr;
}
