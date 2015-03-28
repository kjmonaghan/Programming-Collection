/**
 * Lab10.java
 * Keith Monaghan
 * 2443563
 * 4-14-14
 * Main class, Gathers user input, creates a 2D array, and tests the methods of ArrayHelper.Java
 */

import java.util.Scanner;

public class Lab10 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int rows, cols;
        int[][] myArray;
        
        System.out.print("How many rows?: ");
        rows = input.nextInt();
        
        System.out.print("How many columns?: ");
        cols = input.nextInt();
        
        myArray = new int[rows][cols];
        
        for(int i = 0; i < rows; i++)
        	for(int j = 0; j < cols; j++){
        		System.out.print("Enter a value for position (" + i + "," + j + "): ");
        		myArray[i][j] = input.nextInt();
        	}
        
        System.out.print("Here is your array");
        ArrayHelper.print2DArray(myArray);
        
        for(int i = 0; i<rows; i++)
        	System.out.print("\nrow " + i + " sum= " + ArrayHelper.arraySum(myArray[i]) + ", avg = " + ArrayHelper.arrayAvg(myArray[i]));
        
        System.out.println("\nThe sum for the entire array is = " + ArrayHelper.arraySum2D(myArray));
        System.out.println("The average for the entire array is = " + ArrayHelper.arrayAvg2D(myArray)); 
    }
}
