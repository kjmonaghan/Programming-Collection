#include "FarmAnimal.h"
#include "AnimalPen.h"
#include "stackofanything.h"
#include <iostream>

void AnimalPen::addAnimal(FarmAnimal* animal){ StackOfAnything<FarmAnimal*>::push(animal); }

void AnimalPen::releaseAnimal() { delete StackOfAnything<FarmAnimal*>::pop(); }

FarmAnimal* AnimalPen::peakAtNextAnimal() { return StackOfAnything<FarmAnimal*>::peek(); }

bool AnimalPen::isPenEmpty(){ return StackOfAnything<FarmAnimal*>::isEmpty(); }

AnimalPen::~AnimalPen(){
	while(!isPenEmpty())
		releaseAnimal();
}
