// Keith Monaghan - 2443563
// SumOfDigits.Java
// Computes the sum of the digits of an integer
// 3/3/14

import java.util.Scanner;

public class SumOfDigits {
	
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		boolean cont = true;
		
		while(cont){
			System.out.println("Please enter a No:");
			int x = input.nextInt();
			input.nextLine();
			System.out.println("The sum of the digits is:" + addDigits(x));
			
			System.out.println("\nWant to try again?(y=1/n=0):");
			x = input.nextInt();
			input.nextLine();
			
			if(x == 0){
				cont = false;
				System.out.println("Thank you!");
			}
			else
				System.out.println();	
		}
	}
	
	public static int addDigits(int x){
		String s = Integer.toString(x);
		int result = 0;
		for(int i = s.length(); i>0; i--)
			result += Integer.parseInt(s.substring(i-1, i));
		
		return result;
	}
}