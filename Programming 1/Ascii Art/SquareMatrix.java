/*
	File Name: SquareMatrix.java 
	Author: Keith Monaghan
    KUID: 2443563
	Email Address: k970m044@ku.edu
	Homework Assignment Number: Homework #2 
	Description: Prints a square matrix and it's transpose
	Last Changed: 3/4/14
 */
 
import java.util.Scanner;

public class SquareMatrix {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		//Collects user input
		System.out.println("Enter the size of the Square Matrix:");
		int size = input.nextInt();
		
		//Prints the two matrices
		System.out.println("Square Matrix:");
		Matrix(size);
		
		System.out.println("Transpose:");
		Transpose(size);
		
	}
	
	//Prints the square matrix
	public static void Matrix(int size){
		
		int maxDigits = Integer.toString((size*size)).length();
		
		for(int i = 1; i<=(size*size); i++){
			System.out.print(i + " ");
			
			//This for loop ensures proper spacing for matrices larger than 3x3
			for(int x = Integer.toString(i).length(); x<maxDigits; x++)
				System.out.print(" ");			
			
			if(i % size == 0)
				System.out.println();

		}
	}
	
	//Prints the transpose of the square matrix
	public static void Transpose(int size){
		
		int maxDigits = Integer.toString((size*size)).length();
		
		for(int i = 1; i<=size; i++){
			if(i != 1)
				System.out.println();
			for(int x = 0; x<size; x++){
				System.out.print((i + x*size) + " ");
				
				//This for loop ensures proper spacing for matrices larger than 3x3
				for(int y = Integer.toString(i + x*size).length(); y<maxDigits; y++)
					System.out.print(" ");
			}
		}
	}
}