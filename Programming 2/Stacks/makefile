Lab2: main.o Box.o StackOfBoxes.o
	g++ -g -std=c++11 main.o Box.o StackOfBoxes.o -o Lab2

main.o: main.cpp StackOfBoxes.h
	g++ -g -std=c++11 -c main.cpp

StackOfBoxes.o: StackOfBoxes.cpp StackOfBoxes.h Box.h
	g++ -g -std=c++11 -c StackOfBoxes.cpp

Box.o: Box.h Box.cpp
	g++ -g -std=c++11 -c Box.cpp

clean:
	rm *.o main
	clean done
