/** 
 * Pokemon.Java
 * Keith Monaghan
 * 2443563
 * 4-11-14
 * Main class.  Creates two pokemon and handles combat.
 */

import java.util.Scanner;

public class Colosseum{
	public static void main(String[] args){
		
		//Neccessary Variables
		Dice d10 = new Dice(10);
		
		int roll = d10.roll();
		int round = 1;
		boolean dead1 = false;
		boolean dead2 = false;
		
		Pokemon player1 = new Pokemon();
		Pokemon player2 = new Pokemon();
		
		Scanner input = new Scanner(System.in);
		
		//Build Pokemon
		System.out.println("Player 1, build your Pokemon!\n=====================");
		player1.userBuild();
		
		System.out.println("\nPlayer 2, build your Pokemon!\n=====================");
		player2.userBuild();
		
		//Determines attack order
		System.out.println("\nPlayer 1 will roll a D10, 6 or higher to go first.");
		
		//Combat
		if(roll >= 6){
			System.out.println("Player 1 rolls a " + roll + " and will go first");
			
			while(!dead1 && !dead2 && (round <= 10)){
				System.out.println("\nRound " + round + "!\n");
				dead2 = player1.attack(player2);
				if(!dead1)
					dead1 = player2.attack(player1);
				round++;
			}
			
			if(!dead1 && !dead2)
				System.out.println("Both fighters are still standing! It's a draw!");
			else if(dead1)
				System.out.println(player1.getName() + " has been defeated!");
			else
				System.out.println(player2.getName() + " has been defeated!");
		}
		else{
			System.out.println("Player 1 rolls a " + roll + " and will go second");
			
			while(!dead1 && !dead2 && (round <= 10)){
				System.out.println("\nRound " + round + "!\n");
				dead1 = player2.attack(player1);
				if(!dead1)
					dead2 = player1.attack(player2);
				round++;
			}
			
			if(!dead1 && !dead2)
				System.out.println("Both fighters are still standing! It's a draw!");
			else if(dead1)
				System.out.println(player1.getName() + " has been defeated!");
			else
				System.out.println(player2.getName() + " has been defeated!");
		}
	}
}