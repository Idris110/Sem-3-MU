package expt1;
import java.util.Scanner;

public class gradeToPerc {
    public static void main(String[] args) {
        char grade;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your grade ");
        grade=sc.next().charAt(0);
        System.out.print("You have scored between ");
        switch(grade)
        {
            case 'A':
            System.out.print("91% to 100%");
            break;

            case 'B':
            System.out.print("81% to 90%");
            break;

            case 'C':
            System.out.print("71% to 80%");
            break;

            case 'D':
            System.out.print("61% to 70%");
            break;

            case 'F':
            System.out.print("0% to 60%");
            break;
        }      
        sc.close();
    }

    
}
