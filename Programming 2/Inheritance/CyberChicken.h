//CyberChicken.h
//Keith Monaghan
//9-30-14

#ifndef _CYBER_CHICKEN
#define _CYBER_CHICKEN
#include "Chicken.h"

class CyberChicken : public Chicken{
	public:

		//Constructor
		CyberChicken() { Chicken(); m_name = "Cyber Chicken"; m_sound = "Reisistance is futile";}
		
		//Returns m_eggs
		int getCyberEggs() const { return m_eggs; }
		
		//Sets m_eggs equal to the given int
		void setCyberEggs(int eggs) { m_eggs = eggs; }
};

#endif
