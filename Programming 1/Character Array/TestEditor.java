/*
 *Keith Monaghan
 *2443563
 *TestEditor.java
 *Creates a LineEditor and tests all of its methods
 */
 
 //This program has one bug that I just could not fix.  
 //The while loop will only print the menu once
 //The program will continue to accept further menu selections, though
 //If you change the menu functions to NOT print the array, the loop will function normally.
 
import java.util.Scanner;

public class TestEditor {

    public static void main(String[] args) {
    	
    	//Required variables
    	Scanner a = new Scanner(System.in);
    	LineEditor b;
    	int start, end, selection;
    	String s;
    	String input = new String();
        boolean success;
    	
    	//Accepts a String for the Line Builder
    	System.out.println("+++++++ LineEditor starts... +++++++\n");
    	
    	boolean flag = false;
    	
    	while(!flag){
    		System.out.println("* Write the text you want (maximum length: 100):");
    	    input = a.nextLine();
    	    
    		if(input.length() <= 100){
    			flag = true;
    		}
    		else
    			System.out.println("\n* Operation failed: You exceeded the maximum length.\n");
    	}
    	
    	//Initializes LineEditor
    	b = new LineEditor(input);
    	
    	//Runs the menu selection
    	do{
    		System.out.println("\n--------------------------------------\n");
    		System.out.println("* Choose the menu:\n1. Insert\n2. Delete\n3. Replace\n4. Quit ");
    		
    		selection = a.nextInt();
    		
    		if(selection == 1){
    			System.out.println("\n* Enter the starting position:");
    			start = a.nextInt();
    			a.nextLine();
    					
    			System.out.println("\n* Enter the text you want to insert:");
    			s = a.nextLine();
    					
    			success = b.insert_text(s, start);
    					
    			if(!success){
    				System.out.println("\n* Operation failed: You exceeded the maximum length.\n");
    			}
    			else{
    				System.out.println();
    				System.out.println(b.getString());
    			}
    		}	
    		else if(selection == 2){
    			System.out.println("\n* Enter the starting and ending position for deletion.");
    			start = a.nextInt();
    			end = a.nextInt();
    			a.nextLine();
    					
    			b.delete_text(start, end);
    			
				System.out.println(b.getString());
    		}
    		else if(selection == 3){	
				System.out.println("\n* Enter the starting and ending position for deletion.");
    			start = a.nextInt();
    			end = a.nextInt();
    			a.nextLine();
    					
    			System.out.println("\n* Enter the text you want to replace:");
    			s = a.nextLine();
    					
    			success = b.replace_text(s, start, end);
    					
    					
    			if(!success){
    				System.out.println("\n* Operation failed: You exceeded the maximum length.\n");
    			}
    			else{
    				System.out.println(b.getString());
    			}
    		}			
    		else if(selection == 4){
    			System.out.println("\nGood bye!");
    		}
    		else{
    			System.out.println("Invalid Selection");
    		}
    	}while(selection != 4);
    }
}
