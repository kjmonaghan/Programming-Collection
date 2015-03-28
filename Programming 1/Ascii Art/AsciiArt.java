/*
	File Name: AsciiArt.java 
	Author: Keith Monaghan
    KUID: 2443563
	Email Address: k970m044@ku.edu
	Homework Assignment Number: Homework #2 
	Description: Prints Ascii art using nested for loops
	Last Changed: 3/4/14
 */

import java.util.Scanner;

public class AsciiArt {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int size = 5, pattern = 0;
		
		//Collecting user input
		System.out.print("Choose one of the following patterns by typing the corresponding number: \n1) Grid \n2) Checker Board\n3) Reverse Diagonal\n");
		
		pattern = input.nextInt();
		input.nextLine();
		
		if(pattern == 1 || pattern == 2 || pattern == 3){
			System.out.println("\nInput a size (must be larger than 1):");
			size = input.nextInt();		
		}
		else
			System.out.println("\nError.");
		
		//Calls the correct method to print the desired pattern
		if(size > 1)
			switch(pattern){
				case 1: Grid(size);
				break;
			
				case 2: CheckerBoard(size);
				break;
			
				case 3: ReverseDiagonal(size);
				break;
			}
		else
			System.out.println("\nError.");
	}
	
	//Prints the Grid
	public static void Grid(int size){
		for(int i = size; i>0; i--){
			System.out.print("\n" + (size - i) + " ");
			for(int x = size; x>0; x--)
				System.out.print("* ");
		}
	}
	
	//Prints the CheckerBoard
	public static void CheckerBoard(int size){
		for(int i = size; i>0; i--){
			if((size-i) % 2 == 0){
				System.out.print("\n" + (size - i) + " ");
				for(int x = (size/2 + 1); x>0; x--)
					System.out.print("*   ");
			}
			else{
				System.out.print("\n" + (size - 1) + "   ");
				for(int x = (size/2); x>0; x--)
					System.out.print("*   ");
			}
		}
	}
	
	//Prints the ReverseDiagonal
	public static void ReverseDiagonal(int size){
		for(int i = size; i>0; i--){
			System.out.print("\n" + (size - i) + " ");
			for(int x = i; x>0; x--){
				if(x == 1)
					System.out.print("*");
				else
					System.out.print("  ");
			}
		}
	}
}