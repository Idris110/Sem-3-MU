class Areas{
    Areas(int l){
        System.out.println("Area of square is "+l*l);
    }
    Areas(int l,int b){
        System.out.println("Area of square is "+l*b);
    }
    Areas(float r){
        System.out.println("Area of square is "+3.142*r*r);
    }
}

public class AreaConstOL {
    public static void main(String[] args) {
        new Areas(12);
        new Areas(12*4);
        new Areas((float)5);
    }
}
