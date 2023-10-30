    public class ExceptionHandling{
        public static void main(String[] args) {
            System.out.println("\nArithmetic Exception :");
            try {
                int a=10,b=0;
                int c=a/b;
                System.out.println(c);
            } catch (ArithmeticException e) {
                System.out.println(e);
            }

            System.out.println("\nArray index out of bounds Exception :");
            try {
                int[] a = {10,20,30,40,50};
                System.out.println(a[5]);   
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println(e);
            }

            System.out.println("\nNull pointer Exception :");
            try{
                StringBuffer[] str = new StringBuffer[4];
                str[0].append("Hello");
                System.out.println(str[0]); 
            } catch(NullPointerException e){
                System.out.println(e);
            }
        }
    }