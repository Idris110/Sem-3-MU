package expt2;
 
 
 public class twodTableSquare {
     public static void main(String[] args) {
         int i;
         for(i=1;i<=25;i++)
         {   
             if(i*i<10) System.out.print(i*i+"   ");
             else if(i*i<100) System.out.print(i*i+"  ");
             else System.out.print(i*i+" ");
             if(i%5==0) System.out.println("");
         }
     }
 }

