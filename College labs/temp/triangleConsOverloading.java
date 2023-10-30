public class Triangle{
    float a,b,c;
    public triangle(float s1)
    {
        a=b=c=s1;
    }
    public triangle(float s1,float s2)
    {
        a=b=s1;
        c=s2;
    }
    public triangle(float s1,float s2,float s3)
    {
        a=s1;
        b=s2;
        c=s3;
    }
    public float perim(){
        return a+b+c;
    }
}

public class triangleConsOverloading {
    public static void main(String[] args) {
        Triangle t1= new Triangle(5.0);
        Triangle t2= new Triangle(5.0,3.0,4.0);
        Triangle t3= new Triangle(5.0,5.0);

        System.out.println("Perimeter of t1 t2 t3 ="+t1.perim+t2.perim+t3.perim);
    }
}