import java.util.Scanner;

public class palindrome{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string : ");
        String inp = sc.next();
        String reversedString = reverseString(inp);

        if (inp.equals(reversedString))  System.out.println(inp + " is a palindrome");
        else  System.out.println(inp + " is not a palindrome");
    }

    private static String reverseString(String inp) {
        StringBuffer buffer = new StringBuffer();
        buffer.append(inp);
        return buffer.reverse().toString();
    }
}