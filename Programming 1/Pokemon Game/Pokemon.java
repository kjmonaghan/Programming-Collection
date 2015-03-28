/** 
 * Pokemon.Java
 * Keith Monaghan
 * 2443563
 * 4-11-14
 * Pokemon object to be used in Colosseum.Java
 */

import java.util.Scanner;

public class Pokemon{
	
	//Pokemon's core variables
	private int hp, attackLevel, defenseLevel;
	private String name;
	private Dice d20, d6;
	
	//Constructor
	public Pokemon(){
		hp = 0;
		attackLevel = 0;
		defenseLevel = 0;
		
		name = "";
		
		d20 = new Dice(20);
		d6 = new Dice(6);
	}
	
	//Completes one attack
	public boolean attack(Pokemon opponent){
		System.out.println(this.getName() + " is attacking " + opponent.getName());
		
		int roll1 = this.d20.roll();
		int roll2 = this.d20.roll();
		
		System.out.println(this.name + " rolls an attack bonus of " + roll1);
		System.out.println(opponent.getName() + " rolls a defense bonus of " + roll2);
		
		if((this.attackLevel + roll1) > (opponent.getDefense() + roll2)){
			System.out.println("The attack hits dealing 3-D6 damage!");
			int roll3 = this.d6.roll();
			int roll4 = this.d6.roll();
			int roll5 = this.d6.roll();
			
			int total = roll3 + roll4 + roll5;
			
			opponent.setHP(opponent.getHP() - total);
			
			System.out.println("The rolls are are " + roll3 + ", " + roll4 + ", and " + roll5 + " totaling: " + total + " damage!");
			
			if(opponent.getHP() <= 0){
				return true;
			}
			else{
				System.out.println(opponent.getName() + " has " + opponent.getHP() + " hit points left");
				return false;				
			}
		}
		else{
			System.out.println("The attack missed!");
			return false;
		}
		
	}
	
	//Interacts with the user to initialize all of the variables.
	public void userBuild(){
		Scanner input = new Scanner(System.in);
		
		System.out.print("Please name your pokemon: ");
		this.name = input.nextLine();
		
		System.out.print("\nHow many hit points will it have? (1-50): ");
		this.hp = input.nextInt();
		while(this.hp < 1 || this.hp>50){
			System.out.print("\nSorry. Hit points must be between 1 and 50: ");
			this.hp = input.nextInt();
		}
		
		System.out.print("\nSplit fifty points between attack level and defense level\nEnter your attack level (1-49): ");
		this.attackLevel = input.nextInt();
		
		while(this.attackLevel < 1 || this.attackLevel > 49){
			System.out.print("\nSorry. The attack level must be between 1 and 49: ");
			this.attackLevel = input.nextInt();
		}
		
		System.out.print("\nEnter your defense level (1-" + (50-this.attackLevel) + "): ");
		this.defenseLevel = input.nextInt();
		
		while(this.defenseLevel < 1 || (this.attackLevel + this.defenseLevel) > 50){
			System.out.print("\nSorry. The defense level must be between 1 and " + (50-this.attackLevel) + ": ");
			this.defenseLevel = input.nextInt();
		}
	}
	
	
	//Get methods 
	public int getHP(){
		return hp;
	}
	
	public int getAttack(){
		return attackLevel;
	}
	
	public int getDefense(){
		return defenseLevel;
	}
	
	public String getName(){
		return name;
	}
	
	//Set methods. 
	//It seems like it would be much easier to just use a constructer for most of these. 
	public void setHP(int health){
		hp = health;
	}
	
	public void setAttack(int attack){
		attackLevel = attack;
	}
	
	public void setDefense(int defense){
		defenseLevel = defense;
	}
	
	public void setName(String NewName){
		name = NewName;
	}
}