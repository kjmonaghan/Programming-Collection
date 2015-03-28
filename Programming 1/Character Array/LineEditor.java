/*
 *Keith Monaghan
 *2443563
 *LineEditor.java
 *Class that contains a char array of size 100.  Contains various methods to manipulate its contents.
 */
 
public class LineEditor {
	
	//Variables
	private char[] text;
	private int size;
	
	//Constructor
    public LineEditor(String s){
    	text = new char[100];
    	size = s.length();
    	this.insert_text(s, 1);
    }
    
    //Returns a String version of the array
    public String getString(){
    	String a = "";
    	for(int i = 0; i<size; i++)
    		a += text[i];
    	System.out.println(a);
    	return a;
    }
    
    //Inserts text at a given starting position
    public boolean insert_text(String s, int start){
    	if(size + s.length() <= 100){
    		char[] temp = new char[100];
    		size = size + s.length();
    		start = start - 1;
    		int realIndex = 0;
    		int stringIndex = 0;
    	
    		for(int i = 0; i<size; i++){
    			if(i<start || i>=(start + s.length())){
    				temp[i] = text[realIndex];
    				realIndex++;
    			}
    			else{
    				temp[i]=s.charAt(stringIndex);
    				stringIndex++;
    			}
    		}
    		text = temp;
    		return true;
    	}
    	else{
    		return false;
    	}
    }
    
    //Replaces text at a given starting and ending point
    public boolean replace_text(String s, int start, int end){
    	if((this.size + s.length() - (end - start)) <= 100){
    		this.delete_text(start, end);
    		this.insert_text(s, start);
    		return true;
    	}
    	else{
    		return false;
    	}
    }
    
    //Deletes a selection of text
    public void delete_text(int start, int end){
    	char[] temp = new char[100];
    	start = start-1;
    	end = end-1;
    	int realIndex = 0;
    	
    	for(int i = 0; i<100; i++)
    		if(i<start || i>end){
    			temp[realIndex] = text[i];
    			realIndex++;
    		}
    	text = temp;
    	
    	size = size - (end - start);	
    }
}