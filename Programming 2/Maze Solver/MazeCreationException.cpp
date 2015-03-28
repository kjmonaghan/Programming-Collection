#include <iostream>
#include <string>
#include <stdexcept>

#include "MazeCreationException.h"

//Pretty much a pointless class
//Renames a runtime error to a MazeCreationException
MazeCreationException::MazeCreationException(const char* message) : std::runtime_error(std::string(message))
{;}