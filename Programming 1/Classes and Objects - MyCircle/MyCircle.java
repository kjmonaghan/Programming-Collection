public class MyCircle {
	private double radius;
	private final double PI = 3.141592;
	
    public MyCircle(double r) {
    	radius = r;
    }
    
    public double diameter(){ return (radius * 2.0); }
    
    public double area(){ return (PI * radius * radius); }
    
    public double circumference() { return (2.0 * PI * radius); }
    
}