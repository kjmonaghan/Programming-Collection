#ifndef INCLUDED_BOX
#define INCLUDED_BOX

class Box{
	public:
		Box();
		void setValue(int val);
		int getValue();
		void setPrevious(Box* prev);
		Box* getPrevious();
	private:
		int m_value;
		Box* m_previous;
};

#endif // INCLUDED_BOX