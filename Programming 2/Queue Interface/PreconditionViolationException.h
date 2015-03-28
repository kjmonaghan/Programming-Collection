/* 
 * PreconditionViolationException.h
 * Keith Monaghan
 * 9/29/14 
 */

#ifndef _PRECONDITION_VIOLATION_EXCEPTION
#define _PRECONDITION_VIOLATION_EXCEPTION

#include <stdexcept>
#include <string>

using namespace std;

class PreconditionViolationException : public logic_error
{
public:

	//calls the constructor of std::runtime_error, passing it the message
	PreconditionViolationException(const char* message) : logic_error("Precondition Violated Exception: " + std::string(message)) {;}
	
};

#endif