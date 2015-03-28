/*  File Name: Triangles.java 
*	Author: <Keith Monaghan> 
*   KUID: <2443563>
*	Email Address: <k970m044@ku.edu> 
*	Lab Assignment: <Lab 9> 
*	Description: <Creates a pyramid of triangles> 
*	Last Changed: <4/7/14> 
* 
*   Base Code created by Justin Dawson (JDawson@ku.edu)
*/
package edu.ku.eecs168.triangles;


import java.util.Random;

import android.graphics.Color;
import android.os.Bundle;


public class Triangles extends AbsTriangles {

    private int numTriangles = 10; 
    private Random ranGen;
    private int colorType;
    
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		ranGen = new Random();
	}
	
	@Override
	public void onDialogReturned(int num) {
		numTriangles = num;
		repaint();
	}
	

    @Override
    public void colorRows() {
        colorType = 1;
        repaint();
    }

    @Override
    public void colorRandom() {
        colorType = 2;
        repaint();
    }

    @Override
    public void colorGradient() {
        colorType = 3;
        repaint();
    }
	
	// The setColor method of the Graphics class expects color to be specified as a single int.
	// This routine converts RGBalpha values into a single int that setColor can understand.
	// Specify the red, green, blue and alpha values as integers between 0 and 255.
	// Alpha is a transparency component - an alpha of 255 is fully opaque, 
	//   while an alpha of 0 is transparent.
	// The output of rgbToColor is an integer that is in the format expected by setColor,
	// which is specified by a hexidecimal value of the format 0xAARRGGBB
	public int rgbToColor(int red, int green, int blue, int alpha) {
		int color = 0;
		color += blue;
		color += 256*green;
		color += 256*256*red;
		color += 256*256*256*alpha;
		return color;
	}
	
	
	@Override
	public void paint(Graphics canvas) {
		//clear the screen before we draw
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		
		//sets color to blue
		canvas.setColor(Color.BLUE);
		
		//Gets size of triangles
		int base = canvas.getWidth()/numTriangles;
		
		//Draws the triangles
		for(int x = 0; x*base <= canvas.getWidth(); x++)
			for(int y = numTriangles; y>x; y--)
				canvas.drawIsoTriangle(canvas.getWidth()-base*y, canvas.getHeight()-(x*base), base, base);
		
	}
}
