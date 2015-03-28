//Main.cpp
//Keith Monaghan
//9-28-14

#include "Queue.h"
#include "PreconditionViolationException.h"
#include <iostream>
#include <string>

void printMenu(){
	std::cout <<    "Select an action:" 
	<< std::endl << "1) Get in check out lane 1"
	<< std::endl << "2) Get in check out lane 2"
	<< std::endl << "3) See who is at the front of lane 1"
	<< std::endl << "4) See who is at the front of lane 2"
	<< std::endl << "5) Print all names in lane 1"
	<< std::endl << "6) Print all names in lane 2"
	<< std::endl << "7) Check out a customer in lane 1"
	<< std::endl << "8) Check out a customer in lane 2"
	<< std::endl << "9) Compare Queues"
	<< std::endl << "10) Quit"
	<< std::endl << "Enter choice: "
	<< std::endl;
}

template <typename T>
void compareQueues(const QueueInterface<T>& q1, const QueueInterface<T>& q2)
{
	std::cout 	<< "\nComparison of queues:\n"
			<< "lane 1 < lane 2: " <<  (q1 <  q2) 	<< "\n"
			<< "lane 1 > lane 2: " <<  (q1 >  q2) 	<< "\n"
			<< "lane 1 >= lane 2: " << (q1 >= q2) 	<< "\n"
			<< "lane 1 <= lane 2: " << (q1 <= q2) 	<< "\n"
			<< "lane 1 == lane 2: " << (q1 == q2) 	<< "\n"
			<< "lane 1 != lane 2: " << (q1 != q2) 	<< "\n";
}

int main(){
	QueueInterface<std::string>* lane1 = new Queue<std::string>();
	QueueInterface<std::string>* lane2 = new Queue<std::string>();

	bool flag = true;
	int choice;
	string name;

	while(flag){
		printMenu();
		std::cin >> choice;
		std::cout << "You chose: " << choice << std::endl;

		switch(choice){
			case 1:
				std::cout << "Who is going in lane 1?: " << std::endl;
				std::cin >> name;
				lane1->enqueue(name);
				std::cout << name << " successfully added to the lane 1" << std::endl;
				break;

			case 2:
				std::cout << "Who is going in lane 2?: " << std::endl;
				std::cin >> name;
				lane2->enqueue(name);
				std::cout << name << " successfully added to the lane 2" << std::endl;
				break;

			case 3:
				try{
					std::cout << lane1->peekFront() << " is at the front of the lane 1" << std::endl;
				}
				catch(PreconditionViolationException& e){
					std::cout << e.what() << std::endl;
				}
				break;

			case 4:
				try{
					std::cout << lane2->peekFront() << " is at the front of the lane 2" << std::endl;
				}
				catch(PreconditionViolationException& e){
					std::cout << e.what() << std::endl;
				}
				break;

			case 5:
				lane1->print();
				break;

			case 6:
				lane2->print();
				break;

			case 7:
				try{
					name = lane1->dequeue();
					std::cout << name << " checked out from lane 1" << std::endl;
				}
				catch(PreconditionViolationException& e){
					std::cout << e.what() << std::endl;
				}
				break;

			case 8:
				try{
					name = lane2->dequeue();
					std::cout << name << " checked out from lane 2" << std::endl;
				}
				catch(PreconditionViolationException& e){
					std::cout << e.what() << std::endl;
				}
				break;
			case 9:
				compareQueues(*lane1, *lane2);
				break;

			case 10: 
				flag = false;
				std::cout << "Program ending" << std::endl;
				break;
		}

		std::cout << "\n\n";
	}

	delete lane1;
	delete lane2;
	return 0;
}