import java.util.Scanner;

public class maxByclass {

    public static void main(String[] args) {
        max.get();
        System.out.println("Max : "+max.calcMax());
    }
}

class max{
    static int n1;
    static int n2;
    static int n3;
    static void get() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 3 numbers : ");
        n1=sc.nextInt();
        n2=sc.nextInt();
        n3=sc.nextInt();
    }
    static int calcMax(){
        return (n1>n2&&n1>n3)?n1:((n2>n3)?n2:n3);
    }
}