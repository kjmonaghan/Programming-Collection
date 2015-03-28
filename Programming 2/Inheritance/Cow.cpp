#include "Cow.h"

void Cow::setMilkProduced(double gallons){
	if(gallons > 0)
		m_milkProduced = gallons;
	else
		m_milkProduced = 0;
}
