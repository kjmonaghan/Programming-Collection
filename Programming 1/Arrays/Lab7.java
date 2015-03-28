import java.util.Scanner;

public class Lab7 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] a;
        int arraysize = 0;
        
        while(arraysize <= 0){
        	System.out.print("Input an array size: ");
        	arraysize = input.nextInt();
        }
        
        a = new int[arraysize];
        
        System.out.print("Now please enter " + arraysize + " numbers\n");
        
        for(int i = 0; i<arraysize; i++){
        	System.out.print("Input a number into your array: ");
        	a[i] = input.nextInt();
        }
        
       System.out.print("Here are all the numbers in your array: \n");
       
       for(int i = 0; i<arraysize; i++){
       		System.out.println(a[i]);
       }
       
       int sum = 0;
       int largestvalue = 0;
       int smallestvalue = 0;
       
       for(int i = 0; i<arraysize; i++){
       		sum += a[i];
       		if(i == 0){
       			smallestvalue = a[i];
       			largestvalue = a[i];
       		}
       		
       		else{
       			smallestvalue = Math.min(smallestvalue, a[i]);
       			largestvalue = Math.max(largestvalue, a[i]);
       		}
       }
       
       System.out.println("The sum of all the values is: " + sum);
       System.out.println("The average of all the values is: " + (sum/arraysize));
       System.out.println("The largest value is : " + largestvalue);
       System.out.println("The smallest value is : " + smallestvalue);
    }
}
