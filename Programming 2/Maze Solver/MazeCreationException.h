//MazeCreationException.h
//Keith Monaghan

#include <iostream>
#include <string>
#include <stdexcept>

#ifndef MAZE_CREATION_EXCEPTION
#define MAZE_CREATION_EXCEPTION


class MazeCreationException :  public std::runtime_error
{
    
	  public:
		
		//Pretty much a pointless class
		//Renames a runtime error to a MazeCreationException
        MazeCreationException(const char* message);

};
#endif