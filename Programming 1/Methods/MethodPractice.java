// Keith Monaghan - 2443563
// MethodPractice.Java
// Completes three basic tasks using methods
// 3/3/14

import java.util.Scanner;

public class MethodPractice {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		System.out.println("Input a number: ");
		int num = input.nextInt();
		System.out.println("The cube of " + num + " is " + cuber(num));
		input.nextLine();
		
		System.out.println("\nInput two numbers:");
		int a = input.nextInt();
		input.nextLine();
		int b = input.nextInt();
		input.nextLine();
		System.out.println("The larger number is " + chooseGreater(a, b));
		
		System.out.println("\nInput a string:");
		String s = input.nextLine();
		System.out.println("The first letter of " + s + " is " + firstChar(s));
	}
	
	public static int cuber(int num){
		return (num * num * num);
	}
	
	// The wiki said this should be a boolean, but the description of the method says that it should return an int.
	public static int chooseGreater(int a, int b){
		return Math.max(a, b);
	}
	
	public static char firstChar(String s){
		return s.charAt(0);
	}
}