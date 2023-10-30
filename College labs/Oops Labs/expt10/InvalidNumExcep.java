import java.util.*;

class MyException extends Exception {
    MyException(String s) {
        super(s);
    }
}

public class InvalidNumExcep {

    static void check(int num) throws MyException {
        if (num != 5 && num != 6 && num != 7) {
            throw new MyException("Invalid input");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter a number : ");
            int num = sc.nextInt();
            check(num);
            System.out.println("Valid input");
        } catch (Exception e) {
            System.out.println(e);
        }
        sc.close();
    }
}