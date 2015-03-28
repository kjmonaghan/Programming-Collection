//Cow.h
//Keith Monaghan
//9-30-14

#ifndef _COW
#define _COW
#include "FarmAnimal.h"

class Cow : public FarmAnimal{
	protected:
		double m_milkProduced;
	public:

		//Constructor
		Cow(){FarmAnimal(); m_name = "Cow"; m_sound = "Moo";}
		
		//Returns m_milkProduced
		double getMilkProduced() const {return m_milkProduced;}
		
		//Sets m_milkProduced equal to the given double
		void setMilkProduced(double gallons);
};

#include "Cow.cpp"
#endif
