#include <iostream>
#include "Dice.h"
#include "Pokemon.h"

int main()
{
    Pokemon player1;
    Pokemon player2;
    Dice d10 = Dice(10);
    bool isRunning;
    int round = 1;
    int temp;

    std::cout << "Player 1, build your Pokemon!" << endl << "=====================" << endl;

    player1.userBuild();

    std::cout << "\nPlayer 2, build your Pokemon!" << endl << "=====================" << endl;

    player2.userBuild();

    std::cout << "\nPlayer 1 will roll a D10, 6 or higher to go first." << endl;
    temp = d10.roll();
    if(temp > 5){
        std::cout << "Player 1 rolls a " << temp << " and will go first";
        do{
            std::cout << "\n\nRound " << round << "!\n\n";
            isRunning = player1.attack(player2);
            if(!isRunning)
                isRunning = player2.attack(player1);
            if(round == 10){
                std::cout << "Both fighters are still standing! It's a draw!" << endl;
                isRunning = true;
            }
            round++;
        }while(!isRunning);
    }
    else{
        std::cout << "Player 1 rolls a " << temp << " and will go second";
        do{
            std::cout << "\n\nRound " << round << "!\n\n";
            isRunning = player2.attack(player1);
            if(!isRunning)
                isRunning = player1.attack(player2);
            if(round == 10){
                std::cout << "Both fighters are still standing! It's a draw!" << endl;
                isRunning = true;
            }
            round++;
        }while(!isRunning);
    }
}
