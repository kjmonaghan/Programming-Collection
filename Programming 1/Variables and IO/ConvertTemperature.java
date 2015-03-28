/* -----------------------------------------------------------------------------
 *
 * File Name:  ConvertTemperature.java
 * Author: Your name 
 * Assignment:   EECS-168/169 Lab 2
 * Description:  This program will convert the input temperature from Fahrenheit to Celsius.
 * Date: date the program was last modified
 *
 ---------------------------------------------------------------------------- */
//Start your program.
import java.util.Scanner;

public class ConvertTemperature
{
       public static void main(String[] args)
      {
			  double fahrenheit;

              Scanner input = new Scanner(System.in);  
              System.out.println("Enter the temperature in Fahrenheit: ");
              fahrenheit = input.nextDouble();   
              
              System.out.println(fahrenheit + " degrees Fahrenheit = " + (double)((fahrenheit-32.0) * (5.0 / 9.0)) + " degrees Celsius.");
       }
}