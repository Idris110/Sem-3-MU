import java.util.Scanner;

public class OddEven {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array :");
        int n= sc.nextInt();
        int[] a = new int[n];
        System.out.println("Enter the elements:");
        
        for(int i=0;i<n;i++) a[i]= sc.nextInt();

        int even=0,odd=0;
        for(int i=0;i<n;i++){ //this could be done in above loop, but then there is no meaning of Aim.
            if(a[i]%2==0) even++;
            else odd++ ;
        }
        System.out.println("Number of odd elements:"+odd+"\nNumber of even elements:"+even);
    }
}