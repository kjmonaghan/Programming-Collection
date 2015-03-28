//main.cpp
#include <iostream> //cout cin
#include "boxofanything.h" //Template box class
#include "stackofanything.h"

//Prints the menu
void printMenu(){
  std::cout 
  << "Select an action:\n" 
  << "1) Push onto the number stack\n" 
  << "2) Push onto the character stack\n" 
  << "3) Peek at top of number stack\n" 
  << "4) Peek at top of character stack\n" 
  << "5) Pop top of number stack\n" 
  << "6) Pop top of char stack\n" 
  << "7) Check size of number stack\n" 
  << "8) Check size of char stack\n" 
  << "9) Quit\n" 
  << "Enter choice: ";
}

int main()
{
	//Initialize stacks
	StackOfAnything<int> numStack;
	StackOfAnything<char> charStack;
	

	//loop
	bool running = true;
	int num;
	int selection;
	char character;
	
	while(running){
	  //Display options
	  printMenu();
	  
	  //Get selection
	  std::cin >> selection;
	  std::cout << "You selected: " << selection << std::endl;
	  
	  //Handle even selection (manipulates char stack)
	  if(selection%2 == 0){
	    selection = selection/2;
	    switch(selection){
	      case 1:
		std::cout << "Enter a character: ";
		std::cin >> character;
		charStack.push(character);
		std::cout << std::endl << character << " added to stack";
		break;
	      case 2:
		try{
		  std::cout << "The top of the stack is " << charStack.peek() << std::endl;
		}
		catch(std::runtime_error& e){
		  std::cout << e.what() << std::endl;
		}
		break;
	      case 3: 
		try{
		  std::cout << charStack.pop() << " has been removed from the stack" << std::endl;
		}
		catch (std::runtime_error& e){
		  std::cout << e.what() << std::endl;
		}
		break;
	      case 4:
		std::cout << "The char stack contains " << charStack.size() << " characters" << std::endl;
		break;
	    }
	  }
	  
	  //Handle odd selection (manipulates num stack)
	  else{
	    selection = (selection/2) + 1;
	    switch(selection){
	      case 1:
		std::cout << "Enter a number: ";
		std::cin >> num;
		numStack.push(num);
		std::cout << std::endl << num << " added to stack";
		break;
	      case 2:
		try{
		  std::cout << "The top of the stack is " << numStack.peek() << std::endl;
		}
		catch (std::runtime_error& e){
		  std::cout << e.what() << std::endl;
		}
		break;
	      case 3: 
		try{
		  std::cout << numStack.pop() << " has been removed from the stack" << std::endl;
		}
		catch (std::runtime_error& e){
		  std::cout << e.what() << std::endl;
		}
		break;
	      case 4:
		std::cout << "The number stack contains " << numStack.size() << " numbers" << std::endl;
		break;
	      case 5:
		running = false;
		break;
	    }
	  }
	  
	  std::cout << "\n\n";
	}
	
	std::cout << "Exiting...\n\n";
	return(0);
}

