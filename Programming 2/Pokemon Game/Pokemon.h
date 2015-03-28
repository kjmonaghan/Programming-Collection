#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include "Dice.h"

using namespace std;

class Pokemon
{
	public:
	
	Pokemon();
	bool attack(Pokemon& opponent);
	void userBuild();
	int getHP();
	int getAttack();
	int getDefense();
	string getName();
	
	void setHP(int newHP);
	void setAttack(int newATK);
	void setDefense(int newDEF);
	void setName(string newName);
	
	private:
	
	int hp;
	int atk;
	int def;
	string name;
	Dice d20;
	Dice d6;
};

#endif
