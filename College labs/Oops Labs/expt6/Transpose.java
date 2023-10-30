import java.util.Scanner;

public class Transpose {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows and column in matrix :");
        int m=sc.nextInt();
        int n=sc.nextInt();
        int[][] a= new int[m][n];
        int[][] b= new int[n][m];

        System.out.println("Enter the elements of matrix :");

        for(int i=0;i<m;i++) for(int j=0;j<n;j++) a[i][j]=sc.nextInt();
        
        System.out.println("Transposed matrix :");
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) b[j][i]=a[i][j]; 

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) 
            System.out.print(b[i][j]+" ");
            System.out.println();
        }
    }
}