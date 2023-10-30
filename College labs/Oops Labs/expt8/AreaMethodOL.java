class Area{
    int calculateArea(int l){
        return l*l;
    }
    int calculateArea(int l,int b){
        return l*b;
    }
    double calculateArea(float r){
        return 3.142*r*r;
    }
}

public class AreaMethodOL {
    public static void main(String[] args) {
        Area a1= new Area();
        System.out.println("Area of square with sides 12 is "+a1.calculateArea(12));
        System.out.println("Area of rectangle with sides 12 and 4 is "+a1.calculateArea(12,4));
        System.out.println("Area of circle with radius 2 is "+a1.calculateArea((float)2));
    }
}