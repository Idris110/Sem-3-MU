package expt2;

public class pattern1 {
    public static void main(String[] args) {
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3-i;j++)
            {
                System.out.print("  ");
            }
            for(int j=1;j<=i;j++)
            {
                System.out.print("* ");
            }
            for(int j=i;j>=2;j--)
            {
                System.out.print("* ");
            }
            System.out.println("");
        }
        for(int i=2;i>=1;i--)
        {
            for(int j=1;j<=3-i;j++)
            {
                System.out.print("  ");
            }
            for(int j=1;j<=i;j++)
            {
                System.out.print("* ");
            }
            for(int j=i;j>=2;j--)
            {
                System.out.print("* ");
            }
            System.out.println("");
        }
    }
}
