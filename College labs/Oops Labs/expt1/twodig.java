package expt1;
import java.io.*;

public class twodig {
     public static void main(String[] args) throws IOException 
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a number");
        int number = Integer.parseInt(br.readLine());
        if(number<100 && number>9)
        System.out.println("Two dig number");
        else System.out.println("Not a two dig number");
    } 
}