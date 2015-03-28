//Chicken.h
//Keith Monaghan
//9-30-14

#ifndef _CHICKEN
#define _CHICKEN
#include "FarmAnimal.h"

class Chicken : public FarmAnimal{
	protected:
		int m_eggs;

		//Sets m_eggs to eggs
		void setEggs(int eggs) { m_eggs = eggs; }
		
		//Returns m_eggs
		int getEggs() { return m_eggs; }
	public:
		//Constructor
		Chicken() { m_name = "Chicken"; m_sound = "Cluck"; }
};

#endif
