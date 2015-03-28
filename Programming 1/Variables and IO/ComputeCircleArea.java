/* -----------------------------------------------------------------------------
 *
 * File Name:  ComputeCircleArea.java
 * Author: Your name and Email address
 * Assignment:   EECS-168/169 Lab 2
 * Description:  This program will compute the area of the circle, where the radius is received
 *                      from the user.
 * Date: date the program was last modified
 *
 ---------------------------------------------------------------------------- */

import java.util.Scanner;

public class ComputeCircleArea
{
       public static void main(String[] args)
      {
              //Declare the variables and constants.
			  double radius, area;
			  final double PI = 3.141592; 

              //Read the input from the keyboard.
              Scanner input = new Scanner(System.in);  //sets up things to accept keyboard input
              System.out.println("Enter the number for radius:");
              radius = input.nextDouble();   //reads one real number from the keyboard

              area = PI * radius * radius;
              
              //Display the output
              System.out.println("The area for the circle of radius " + radius + " is " + area);
       }
}