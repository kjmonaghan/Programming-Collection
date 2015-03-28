/*
	File Name: PriceCostCalculator.java 
	Author: Keith Monaghan
    KUID: 2443563
	Email Address: k970m044@ku.edu
	Homework Assignment Number: Homework #1 
	Description: Calculates the cost of printing
	Last Changed: 3/2/14
 */

import java.util.Scanner;
public class PrintCostCalculator {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int pages, color, ink;
		char printtype, scale, salechar;
		double cost;
		boolean sale = false;
		
		System.out.print("--- Price Estimator Program --- \nEnter Number of Pages (digits only): ");
		pages = input.nextInt();
		input.nextLine();
		
		System.out.print("\n---- Select a Print Type ---- \nEnter T or t for Text \nEnter I or i for Image \nEnter C or c for Compressed Text \nEnter S or s for statement \n--------------------------- \nEnter Print Type: ");
		printtype = input.nextLine().toLowerCase().charAt(0);
		switch (printtype){
			case 't': ink = 5000;
			break;
			case 'i': ink = 10000;
			break;
			case 'c': ink = 15000;
			break;
			case 's': ink = 7000;
			break;
			default: ink = 0;
			break;
		}
		
		System.out.print("\n--- Select a Print Color --- \nEnter 0 for Grayscale \nEnter 1 for Color \n----------------------------- \nEnter Print Color: ");
		color = input.nextInt();
		input.nextLine();
		System.out.println("-----------------------------");
		System.out.print("Is there a sale (y/n): ");
		salechar = input.nextLine().toLowerCase().charAt(0);
		if(salechar == 'y')
			sale = true;
		
		if(color == 0)
			cost = (0.00001 * (double)ink);
		else
			cost = (0.00005 * (double)ink);
		
		System.out.print("\n--- Cost Estimate ---\nInk Usage Per Page: " + ink);
		System.out.printf("\nTotal Ink Usage: %1.2e \n", (double)(ink * pages));
		System.out.printf("\nEstimated Cost Per Page: $%,.4f%n", cost);
		System.out.printf("Total Cost: $%,.2f", (cost * (double)pages));
		
		if(sale == true)
			System.out.printf("\n\nSALE Price: $%,.2f", (0.5 * cost * (double)pages));

	}
}