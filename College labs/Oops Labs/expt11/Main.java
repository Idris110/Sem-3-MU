import java.util.Scanner;
import Add.*;
import Sub.*;
import Multiply.*;
import Divide.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter two numbers : ");
        int n1=sc.nextInt();
        int n2=sc.nextInt();
        
        System.out.println("Addition : "+Add.add(n1,n2));
        System.out.println("Subtraction : "+Sub.sub(n1,n2));
        System.out.println("multiplition : "+Multiply.multi(n1,n2));
        System.out.println("Division : "+Divide.divide(n1,n2));
        
        sc.close();
    }
}