import java.util.Scanner;

public class SumOfOdd {
    
    public static void main(String[] args){
    	
    	Scanner input = new Scanner(System.in);	
    	System.out.print("Please input a positive integer as the end value: ");
    	int i = input.nextInt();
    	int sum = 0;
    	while(i>0){
    		if(i%2 == 1)
    			sum += i;
    		i--;
    	}
    	System.out.println("The summation is: " + sum);
    }
}