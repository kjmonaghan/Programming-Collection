package edu.ku.eecs168.SmileyFace;

import android.graphics.Color;
import edu.ku.swingemu.AndroidJApplet;

public class SmileyFace extends AndroidJApplet {
	//The value of counter has been initialized to help keep track of current frame
	public int counter=0;

	public void paint(Graphics canvas) {
        //this line clears the screen every time the screen is refreshed
canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());

        //The following lines draws the smiley face on screen when counter==0 is true
if(counter==0){
    canvas.setColor(Color.YELLOW);
	canvas.fillOval(100, 50, 300, 300);
	canvas.setColor(Color.BLACK);
    canvas.drawOval(100, 50, 300, 300);	
	canvas.fillOval(182, 150, 15, 30);
	canvas.fillOval(295, 150, 15, 30);		
	canvas.drawArc(178, 190, 150, 112, 180, 180);

	
                counter = 1;
}else{ //If the counter is not 0 then don't draw anything
    canvas.setColor(Color.YELLOW);
	canvas.fillOval(400, 50, 300, 300);
	canvas.setColor(Color.BLACK);
    canvas.drawOval(400, 50, 300, 300);	
	canvas.fillOval(482, 150, 15, 30);
	canvas.fillOval(595, 150, 15, 30);		
	canvas.drawArc(478, 190, 150, 112, 180, 180);
	
	counter = 0;
	
	}
	}

}
