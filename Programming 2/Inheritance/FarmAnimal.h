//FarmAnimal.h
//Keith Monaghan
//9-30-14

#ifndef FARM_ANIMAL
#define FARM_ANIMAL

class FarmAnimal{
	protected:
		//Member variables
		std::string m_name;
		std::string m_sound;
	public:
		//Constructor
		FarmAnimal(){m_name = "unset"; m_sound = "unset";}
		
		//Returns the name of this animal
		std::string getName() const {return m_name;}
		
		//Sets the name of the animal equal to the given string
		void setName(std::string name) {m_name = name;}
		
		//Returns the sound of this animal
		std::string getSound() const {return m_sound;}
		
		//Sets the sound of this animal equal to the given string
		void setSound(std::string sound){m_sound = sound;}
};

#endif
