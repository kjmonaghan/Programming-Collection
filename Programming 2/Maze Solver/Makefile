Lab08: main.o MazeReader.o MazeWalker.o Position.o MazeCreationException.o
	g++ -g -std=c++11 main.o MazeReader.o MazeWalker.o Position.o MazeCreationException.o -o Lab08

main.o: main.cpp MazeReader.h MazeWalker.h Position.h Position.cpp MazeCreationException.h 
	g++ -g -std=c++11 -c main.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -std=c++11 -c MazeReader.cpp


Position.o: Position.h Position.cpp 
	g++ -g -std=c++11 -c Position.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp Position.h Position.cpp
	g++ -g -std=c++11 -c MazeWalker.cpp
	
MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -c MazeCreationException.cpp

clean:
	rm *.o *~ Lab08
