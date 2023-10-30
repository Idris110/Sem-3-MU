
public class maxOf3Bycmd {
    public static void main(String[] args) {
        
        int[] n = new int[3];
        int max,min;
        
        for(int i=0;i<3;i++){
            n[i]= Integer.parseInt(args[i]);
        }
        max= min= n[0];

        for (int i : n) {
            max =(i>max) ? i : max ;
            min =(i<min) ? i : min ;
        }
        System.out.println(max +" is largest \n"+min +" is smallest");
        
    }
}
