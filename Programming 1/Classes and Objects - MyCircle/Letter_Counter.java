/*
 * Letter_Counter.java
 * Keith Monaghan
 * 2443563
 * 4/28/14
 * Counts the letters in a txt file provided by the user and creates a new txt file with the result
 */
 
import java.io.*;
import java.util.*;

public class Letter_Counter {
    public static void main(String[] args) {
    	//Defining variables
    	Scanner a = new Scanner(System.in);
    	System.out.println("Enter a filename: ");
    	String filename = a.nextLine();
    	String input = "";
    	String line;
    	int[] b = new int[26];
    	for(int i = 0; i<26; i++)
    		b[i] = 0;
    	
		//Reading the input file
		FileReader fstream;
		BufferedReader in;

		try{
			fstream = new FileReader(filename);
			in = new BufferedReader(fstream);			
			while( (line=in.readLine())!=null){
				for(int i = 0; i<line.length(); i++)
					if((int)line.toUpperCase().charAt(i) >= 65 && (int)line.toUpperCase().charAt(i) <= 90)
						b[(int)line.toUpperCase().charAt(i)-65]++;
			}
    		           
			in.close();
		}
		catch (Exception e){}
  		
	
		//Writes output
		try{
  			FileWriter outstream = new FileWriter("output.txt");
  			BufferedWriter out = new BufferedWriter(outstream);	
  			out.write("The file contains the following letters: ");	
  			for(int i = 0; i<26; i++){
  				out.newLine();
  				out.write(((char)(i + 65) + ": " + b[i]));
  			}	
  			
  			out.close();
  		}
  		catch (Exception e){}
  		
  		System.out.println("Output.txt created.");
    }
}
