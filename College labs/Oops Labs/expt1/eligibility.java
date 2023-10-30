package expt1;
import java.io.*;

public class eligibility {
    public static void main(String[] args) throws IOException{
        int p,c,m,total;
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter your Physics, Chemistry, Maths marks :");
        p=Integer.parseInt(br.readLine());
        c=Integer.parseInt(br.readLine());
        m=Integer.parseInt(br.readLine());
        total=p+c+m;
        if(p>=50 && c>=40 && m>=60 && total>=200) System.out.println("You are eligible for admission !");
        else System.out.println("You are not eligible for admission !");
    }
}
