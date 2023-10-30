package expt2;
 

 import java.io.*;

    public class vovels {
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter a character :");
            char c = Character.toLowerCase((char)br.read());
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') System.out.println("Vovel");
            else System.out.println("consonant");
        }
    }

