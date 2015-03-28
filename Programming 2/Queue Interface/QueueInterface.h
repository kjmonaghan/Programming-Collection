//QueueInterface.h
//Keith Monaghan
//9-28-14

#ifndef _QUEUE_INTERFACE
#define _QUEUE_INTERFACE 

#include "PreconditionViolationException.h"

template<class T>
class QueueInterface
{
public:
	virtual ~QueueInterface() {};

	//returns true if the queue is empty, false otherwise
	virtual bool isEmpty() const = 0;
	
	//Entry added to back of queue
	virtual void enqueue(const T newEntry) = 0;

	/*
	 * assumes the queue is not empty
	 * front of the queue is removed
	 * returns the value of the entry at the front of the queue
	 * throws PreconditionViolationException when a dequeue is attempted on an empty stack.  Does not return a vlue in this case
	 */

	virtual T dequeue() throw(PreconditionViolationException) = 0;

	
	//assumes the queue is not empty
	//returns the value at the front of the queue
	//throws a PreconditionViolationException is attempted on an empty queue.  Does not return a value in this case.   
	virtual T peekFront() const throw(PreconditionViolationException) = 0;

	//returns the size of the queue
	virtual int size() const = 0;

	//prints the contents of the queue or "Queue Empty" if it is empty
	virtual void print() const = 0;

	//returns true of this queue's size is less than the rhs's size
	virtual bool operator< (const QueueInterface<T>& rhs) const = 0;

	//returns true of this queue's size is less than or equal to the rhs's size
	virtual bool operator<= (const QueueInterface<T>& rhs) const = 0;

	//returns true of this queue's size is greater than the rhs's size
	virtual bool operator> (const QueueInterface<T>& rhs) const = 0;

	//returns true of this queue's size is greater than or equal to than the rhs's size
	virtual bool operator>= (const QueueInterface<T>& rhs) const = 0;

	//returns true of this queue's size is equal to the rhs's size
	virtual bool operator== (const QueueInterface<T>& rhs) const = 0;

	//returns true of this queue's size is not equal to the rhs's size
	virtual bool operator!= (const QueueInterface<T>& rhs) const = 0;
};

#endif
