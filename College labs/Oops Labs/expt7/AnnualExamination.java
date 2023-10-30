import java.util.Scanner;

class Student{
    int phy,chem,math,total;
    Scanner sc = new Scanner(System.in);
    
    Student(int i){
        System.out.println("Student "+(i+1)+" enter your marks in ");
        System.out.print("physics : ");
        phy=sc.nextInt();
        System.out.print("Chemistry : ");
        chem=sc.nextInt();
        System.out.print("Maths : ");
        math=sc.nextInt();
        total= phy+chem+math;
    }
}

public class AnnualExamination {
    public static void main(String[] args) {
        int n=5,max=0;
        Student[] s = new Student[n];

        for(int i=0;i<n;i++) s[i] =new Student(i);

        System.out.println("\nStudent\tPhy\tChem\tMath\tTotal\n---------------------------------------");
        for(int i=0;i<n;i++){
            System.out.println((i+1)+"\t"+s[i].phy+"\t"+s[i].chem+"\t"+s[i].math+"\t"+s[i].total);
            max = (s[i].total>s[max].total) ? i : max;
        }
        System.out.println("\nHighest marks("+s[max].total+") are scored by student "+(max+1)+".");
    }
}
