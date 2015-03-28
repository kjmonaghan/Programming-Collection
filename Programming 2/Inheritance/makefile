Lab04: main.o
	g++ -g -std=c++11 main.o -o Lab04

main.o: main.cpp AnimalPen.h Chicken.h CyberChicken.h FarmAnimal.h Cow.h boxofanything.h boxofanything.hpp stackofanything.h stackofanything.hpp
	g++ -g -c -std=c++11 main.cpp

Cow.o: Cow.h
	g++ -g -c -std=c++11 cow.cpp

AnimalPen.o: AnimalPen.h stackofanything.h FarmAnimal.h
	g++ -g -c -std=c++11 AnimalPen.cpp
clean:
	rm *.o Lab04
