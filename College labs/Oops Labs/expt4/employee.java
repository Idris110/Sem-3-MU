import java.util.Scanner;

public class employee {

    public static void main(String[] args) {
        emp e1= new emp();
        e1.register();
        e1.print();
    }
}

class emp{
    int id,salary;
    String name;
    Scanner sc= new Scanner(System.in);
    void register() {
		System.out.println("Enter name:");
		name = sc.nextLine();
		System.out.println("\nEnter id number:");
		id = sc.nextInt();
		System.out.println("\nEnter salary:");
		salary = sc.nextInt();
	}
    void print(){
		System.out.println("\nName: " +name + "\nId: " +id + "\nSalary: " + salary);
    }
}