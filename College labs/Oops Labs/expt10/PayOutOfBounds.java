import java.util.Scanner;

class PayOutOfBoundsException extends Exception{
    PayOutOfBoundsException(String s){
        super(s);
    }
}

public class PayOutOfBounds {
    static void basicPayCheck(int salary)throws PayOutOfBoundsException{
        if(salary<25000 || salary>50000){
            throw new PayOutOfBoundsException("Pay "+salary+" out of bounds");
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter basic pay :");
        int salary= sc.nextInt();

        try{
            basicPayCheck(salary);
            System.out.println("Basic pay is valid");
        }
        catch(Exception e){
            System.out.println(e);
        }
        sc.close();
    }
}
