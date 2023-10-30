import java.util.Scanner;
 
public class sumOfDiagonal {

    public static int sum(int a[][]) {
        if(a.length==a[0].length){
            int sum=0;
            for(int i=0;i<a.length;i++) 
            for(int j=0;j<a[0].length;j++) 
            sum=(i==j)?(sum+a[i][j]):sum;
            return sum;  
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows and column in matrix :");
        int m=sc.nextInt();
        int n=sc.nextInt();
        int[][] a= new int[m][n];

        System.out.println("Enter the elements of matrix :");

        for(int i=0;i<m;i++) for(int j=0;j<n;j++) a[i][j]=sc.nextInt();

        int sum=sum(a);
        if(sum==-1) System.out.println("Given matrix is not a square matrix");
        else System.out.println("Sum of diagonal elements : "+sum);       
    }
}
