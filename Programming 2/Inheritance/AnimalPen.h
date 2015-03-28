#ifndef _ANIMAL_PEN
#define _ANIMAL_PEN
#include "stackofanything.h"
#include "FarmAnimal.h"

class AnimalPen : public StackOfAnything<FarmAnimal*>
{
	public:
		AnimalPen() : StackOfAnything<FarmAnimal*>() {;}
		~AnimalPen();
		void addAnimal(FarmAnimal* animal);
		FarmAnimal* peakAtNextAnimal();
		void releaseAnimal();
		bool isPenEmpty();
};

#include "AnimalPen.cpp"
#endif
