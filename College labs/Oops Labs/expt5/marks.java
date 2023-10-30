import java.util.Scanner;

public class marks {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[6];
        System.out.println("Enter the marks of 6 subjects(out of 100):");
        
        for(int i=0;i<6;i++) a[i]= sc.nextInt();

        int sum=0,highest=0;
        for(int i=0;i<6;i++){ 
            sum=sum+a[i];
            highest=(highest<a[i]) ? a[i]:highest;
        }
        System.out.println("Total marks scored :"+sum+"/600\nHighest marks are scored is :"+highest);
    }
}
