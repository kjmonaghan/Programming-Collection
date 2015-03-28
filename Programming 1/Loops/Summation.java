/*
 *  <Summation.java>
 *
 *  Created by <Keith Monaghab>
 *  Contact Email: <k970m044@ku.edu>
 *  Description: <Sums consecutive integers from a user given k to n>
 *  Date: <2/24/14>
 * 
 */
import java.util.Scanner;

public class Summation {

    public static void main(String[] args){
    	Scanner input = new Scanner(System.in);	
    	
    	System.out.println("Welcome! This program calculates the summation of consecutive integers.");
    	System.out.println();
    	
    	System.out.print("Please input a positive integer as the initial value: ");
    	int k = input.nextInt();
    	
    	System.out.print("Please input a positive integer as the end value: ");
    	int n = input.nextInt();
    	
    	while(k >= n){
    		System.out.println();
    		System.out.print("The end value is invalid. Please input a positive integer greater than initial value as the end value: ");
    		n = input.nextInt();
    	}
    	
    	int sum = 0;
    	
    	for(int i = k; i<=n; i++)
    		sum += i;
    	
    	System.out.println();
    	System.out.println("The summation is: " + sum);
    }
    
}