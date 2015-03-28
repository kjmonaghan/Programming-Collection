#include <iostream>
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"
#include "AnimalPen.h"

void goodbyeMessage(const FarmAnimal& animal){
	std::cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << "." << std::endl;
}

void printMenu(){
	std::cout << "Select an animal to add to the pen: \n1.) Cow (produces milk)\n2.) Chicken (cannot lay eggs)\n3.) Cyber Chicken (seems dangerous, but lays eggs)\n---------------------------------------------------\nChoice: ";
}

void emptyPen(AnimalPen& pen){
	int eggs = 0;
	double milk = 0;	
	FarmAnimal* temp = nullptr;	
	std::cout << "Releasing all animals!\n-------------------------\n";
	while(!pen.isPenEmpty()){
		temp = pen.peakAtNextAnimal();
		if (temp->getName() == "Cow"){
			Cow* tempCow = static_cast<Cow*>(temp);
			std::cout << "This Cow produced " << tempCow->getMilkProduced() << " gallons of milk" << std::endl;
			milk += tempCow->getMilkProduced();
			goodbyeMessage(*temp);
		}
		else if (temp->getName() == "Cyber Chicken"){
			CyberChicken* tempChick = static_cast<CyberChicken*>(temp);
			std::cout << "This Cyber Chicken laid " << tempChick->getCyberEggs() << " cyber eggs. Humanity is in trouble." << std:: endl;
			eggs += tempChick->getCyberEggs();
			goodbyeMessage(*tempChick);
		}
		else if (temp->getName() == "Chicken"){
			std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help?" << std::endl;
			goodbyeMessage(*temp);
		}

		pen.releaseAnimal();
	}
	
	std::cout << "Your farm produced " << milk << " of milk and " << eggs << " eggs."; 
}

void menuOperator(AnimalPen& pen, int choice){
	int eggs;
	double milk;
	
	Cow* tempCow;
	CyberChicken* tempCyber;
	
	switch(choice){
		case 1:
			std::cout << "How many gallons of milk did this cow produce?: ";		
			std::cin >> milk;
			tempCow = new Cow();
			tempCow->setMilkProduced(milk);
			pen.addAnimal(tempCow);
			break;
		case 2: 
			std::cout << "Add an eggless chicken to the pen? OK. You're the boss." << std::endl;
			pen.addAnimal(new Chicken());
			break;
		case 3:
			std::cout << "How many eggs did this cyber chicken produce?: ";
			std::cin >> eggs;
			tempCyber = new CyberChicken();
			tempCyber->setCyberEggs(eggs);
			pen.addAnimal(tempCyber);
			break;
	}

	tempCow = nullptr;
	tempCyber = nullptr;	
}			
			
int main()
{
	AnimalPen pen;
	char flag = 'n';
	int choice;
	
	while(flag == 'n'){
		printMenu();
		std::cin >> choice;
		menuOperator(pen, choice);
		std::cout << "Done adding animals? (y/n): ";
		std::cin >> flag;
	}

	emptyPen(pen);

    return 0;
}
