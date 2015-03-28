/**
 * Dice.Java
 * Keith Monaghan
 * 2443563
 * 4-11-14
 * Object used to simulate various sizes of dice.  To be used in Colosseum.Java
 */

import java.util.Random;

public class Dice{
	
	//Dice's variables
	private int numSides;
	private Random myRand;
	
	//Constructor
	public Dice(int sides){
		numSides = sides;
		myRand = new Random();
	}
	
	//Rolls the dice and returns the outcome
	public int roll(){
		return (myRand.nextInt(numSides-1) + 1);
	}
}