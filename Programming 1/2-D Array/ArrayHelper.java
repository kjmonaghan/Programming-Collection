/**
 * ArrayHelper.java
 * Keith Monaghan
 * 2443563
 * 4-14-14
 * Helper class.  Has five static methods that access 1D and 2D arrays.
 */
 
public class ArrayHelper{
	
	public static void print2DArray(int[ ][ ] array){
		for(int i = 0; i < array.length; i++){
		System.out.println();
   			for (int j = 0; j < array[i].length; j++)
       			System.out.print(array[i][j] + ", ");
			}
    }
	
	public static int arraySum(int[ ] array){
		int sum = 0;
		for(int i = 0; i<array.length; i++)
			sum += array[i];
		return sum;
	}
	
	public static double arrayAvg(int[ ] array){
		return arraySum(array)/((double)array.length);
	}
	
	public static int arraySum2D(int[ ][ ] array){
		int sum = 0;
		for(int i = 0; i < array.length; i++)
   			for (int j = 0; j < array[i].length; j++)
       			sum += array[i][j];
       	return sum;
	}
	
	public static double arrayAvg2D(int[ ][ ] array){
		return arraySum2D(array)/((double)(array.length*array[0].length));
	}
}