//Queue.h
//Keith Monaghan
//9-28-14

#ifndef _QUEUE
#define _QUEUE 

#include "QueueInterface.h"
#include "boxofanything.h"

template<class T>
class Queue : public QueueInterface<T> {
private:
	BoxOfAnything<T>* m_back;
	BoxOfAnything<T>* m_front;
	int m_size;

public:
	Queue() { m_back = nullptr; m_front = nullptr; m_size = 0; }

	virtual ~Queue();

	//returns true if the queue is empty, false otherwise
	virtual bool isEmpty() const { return (m_size == 0); };
	
	//Entry added to back of queue
	virtual void enqueue(const T newEntry);

	/*
	 * assumes the queue is not empty
	 * front of the queue is removed
	 * returns the value of the entry at the front of the queue
	 * throws PreconditionViolationException when a dequeue is attempted on an empty stack.  Does not return a vlue in this case
	 */

	virtual T dequeue() throw(PreconditionViolationException);

	
	//assumes the queue is not empty
	//returns the value at the front of the queue
	//throws a PreconditionViolationException is attempted on an empty queue.  Does not return a value in this case.   
	virtual T peekFront() const throw(PreconditionViolationException);

	//returns the size of the queue
	virtual int size() const { return m_size; };

	//prints the contents of the queue or "Queue Empty" if it is empty
	virtual void print() const;

	//returns true of this queue's size is less than the rhs's size
	virtual bool operator< (const QueueInterface<T>& rhs) const;

	//returns true of this queue's size is less than or equal to the rhs's size
	virtual bool operator<= (const QueueInterface<T>& rhs) const;

	//returns true of this queue's size is greater than the rhs's size
	virtual bool operator> (const QueueInterface<T>& rhs) const;

	//returns true of this queue's size is greater than or equal to than the rhs's size
	virtual bool operator>= (const QueueInterface<T>& rhs) const;

	//returns true of this queue's size is equal to the rhs's size
	virtual bool operator== (const QueueInterface<T>& rhs) const;

	//returns true of this queue's size is not equal to the rhs's size
	virtual bool operator!= (const QueueInterface<T>& rhs) const;
};

#include "Queue.hpp"

#endif