import java.util.Scanner;

public class Pyramid {
	
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the number of asterisks for the base of the triangle: ");
		int base = input.nextInt();
		
		for(int i = 1; i<=base; i++){
			System.out.println();
			for(int x = i; x>0; x--)
				System.out.print('*');			
		}
	}
}