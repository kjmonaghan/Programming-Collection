#include "Box.h"

class StackOfBoxes{
	private:
		Box* m_top;
		int m_size;
	
	public:
		StackOfBoxes();
		~StackOfBoxes();
		bool isEmpty() const;
		int size() const;
		void push(int value);
		int pop();
};