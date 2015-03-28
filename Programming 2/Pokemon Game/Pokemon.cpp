#include "Pokemon.h"
#include "Dice.h"
#include <string>

Pokemon::Pokemon()
{
    this->hp = 0;
    this->atk = 0;
    this->d6 = Dice(6);
    this->d20 = Dice(20);
    this->def = 0;
    this->name = "";
}

int Pokemon::getAttack(){
    return(this->atk);
}

int Pokemon::getDefense(){
    return(this->def);
}

int Pokemon::getHP(){
    return(this->hp);
}

string Pokemon::getName(){
    return(this->name);
}

void Pokemon::setAttack(int newATK){
    this->atk = newATK;
}

void Pokemon::setDefense(int newDEF){
    this->def = newDEF;
}

void Pokemon::setHP(int newHP){
    this->hp = newHP;
}

void Pokemon::setName(string newName){
    this->name = newName;
}

void Pokemon::userBuild(){
    std::cout << "Please name your pokemon: ";
    std::cin >> this->name;
    do{
        std::cout << "\nHow many hit points will it have? (1-50): ";
        std::cin >> this->hp;
    }while(this->hp < 1 || this->hp > 50);

    std::cout << "Split fifty points between attack level and defense level" << endl << "Enter your attack level (1-49): ";
    std::cin >> this->atk;

    while(this->atk < 1 || this->atk > 49){
        std::cout << "\nSorry. The attack level must be between 1 and 49: ";
        std::cin >> this->atk;
    }

    std::cout << "Enter your defense level (1-" << (50-this->atk) << "): ";
    std::cin >> this->def;

    while(this->def < 1 || this->def > (50-this->atk)){
        std::cout << "Sorry. The defense level must be between 1 and " << (50-this->atk) << ": ";
        std::cin >> this->def;
    }
}

bool Pokemon::attack(Pokemon &opponent){
    int temp;
    int temp2;
    int temp3;

    std::cout << this->name << " is attacking " << opponent.getName() << endl;
    temp = this->d20.roll();
    std::cout << this->name << " rolls an attack bonus of " << temp << endl;
    temp2 = this->d20.roll();
    std::cout << opponent.getName() << " rolls a defense bonus of " << temp2 << endl;

    if((this->atk + temp) > (opponent.getDefense() + temp2)){
        std::cout << "The attack hits dealing 3-D6 damage!" << endl;

        temp = this->d6.roll();
        temp2 = this->d6.roll();
        temp3 = this->d6.roll();

        std::cout << "The rolls are " << temp << ", " << temp2 << ", and " << temp3 << " totaling: " << (temp + temp2 + temp3) << " damage!" << endl;
        opponent.setHP((opponent.getHP()-(temp + temp2 + temp3)));
        if(opponent.getHP() < 1){
            std::cout << opponent.getName() << " has been defeated!" << endl;
            return true;
        }
        else{
            std::cout << opponent.getName() << " has " << opponent.getHP() << " hit points left" << endl;
            return false;
        }
    }

    else{
        std::cout << "The attack missed!" << endl;
        return false;
    }
}
