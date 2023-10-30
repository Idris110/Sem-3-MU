class Staff{
    int code;
    String name,address;

    Staff(int code,String name,String address){
        this.code=code;
        this.name=name;
        this.address=address;
    }
    void staffPrint(){
        System.out.println("Code : "+code+"\nName : "+name+"\nAddress : "+address);
    }
}

class Teacher extends Staff{
    String subject,Class;

    Teacher(int code,String name,String address,String subject,String Class){
        super(code, name, address);
        this.subject=subject;
        this.Class=Class;
    }
    void print(){
        staffPrint();
        System.out.println("Subject : "+subject+"\nClass : "+Class+"\n");
    }
}

class Officer extends Staff{
    String grade;

    Officer(int code,String name,String address,String grade){
        super(code, name, address);
        this.grade=grade;
    }
    void print(){
        staffPrint();
        System.out.println("Grade : "+grade+"\n");
    }
}

class Typist extends Staff{
    int speed;
    Typist(int code,String name,String address,int speed){
        super(code, name, address);
        this.speed=speed;    
    }
    void typistPrint(){
        staffPrint();
        System.out.println("Speed : "+speed);
    }
}

class Regular extends Typist{
    int basic_pay;
    Regular(int code,String name,String address,int speed,int basic_pay){
        super(code, name, address, speed);
        this.basic_pay=basic_pay;
    }
    void print(){
        typistPrint();
        System.out.println("Basic Pay : "+basic_pay+"\n");
    }
}

class Ad_Hoc extends Typist{
    int basic_pay;
    Ad_Hoc(int code,String name,String address,int speed,int basic_pay){
        super(code, name, address, speed);
        this.basic_pay=basic_pay;
    }
    void print(){
        typistPrint();
        System.out.println("Basic Pay : "+basic_pay+"\n");
    }
}


public class CollegeInheritance {
    public static void main(String[] args) {
        int code,speed,basicPay;
        String name,address,subject,Class,grade;

        name="Juhi J";code=647452;address="Mumbai.";subject="OOPs";Class="B.E";
        Teacher t1 = new Teacher(code, name, address, subject, Class);

        name = "Rakesh M"; code = 567456; grade = "B+";
        Officer o1 = new Officer(code, name, address, grade);

        name = "Sahil K"; code = 238456; speed = 70; basicPay = 20000;
        Regular r1 = new Regular(code, name, address, speed, basicPay);

        name = "Mehir M"; code = 678457; speed = 130; basicPay = 30000;
        Ad_Hoc a1 = new Ad_Hoc(code, name, address, speed, basicPay);

        System.out.println("Teacher :");
        t1.print();
        System.out.println("Officer :");
        o1.print();
        System.out.println("Regular :");
        r1.print();
        System.out.println("Ad Hoc :");
        a1.print();
    }
}