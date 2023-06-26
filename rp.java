import java.util.Scanner;

class Student{
    String name;
    int roll;
    Scanner sc = new Scanner(System.in);
    void disp1(){
        System.out.println("Student Database");
        System.out.println("****************");
    }
    
    void getData(){
        System.out.println("Name: ");
        name = sc.nextLine();
        System.out.println("Roll No: ");
        roll = sc.nextInt();
    }
    void putData(){
        System.out.println("STUDENT NAME: "+name);
        System.out.println("STUDENT ROLL NUM: "+roll);
    }
}

class Marks extends Student{
    int eng, mat, sci, ssc, lang;
    int total;
    Scanner s = new Scanner(System.in);
    void getMarks(){
        getData();
        System.out.println("STUDENT MARKS: ");
        System.out.println("ENGLISH: ");
        eng = s.nextInt();
        System.out.println("LANGUAGE: ");
        lang = s.nextInt();
        System.out.println("MATHEMATICS: ");
        mat = s.nextInt();
        System.out.println("SCIENCE: ");
        sci = s.nextInt();
        System.out.println("SOCIAL SCIENCE ");
        ssc = s.nextInt();
        total = (eng + mat + sci + ssc + lang)/5;
    }
    char calculate(){
        if(total>=90){
            return 'A';
        }
        else if(total<90 && total>=75)
        {
            return 'B';
        }
        else if(total<75 && total>=55)
        {
            return 'C';
        }
        else
        {
            return 'D';
        }
    }
    
    String passFail(){
        char x;
        x = calculate();
        if(x == 'A' || x == 'B' || x == 'C')
        {
            return "PASS";
        }
        return "FAIL";
    }
    
    void putMarks(){
        putData();
        System.out.println("MARKS: ");
        System.out.println("ENGLISH: "+eng);
        System.out.println("LANGUAGE: "+lang);
        System.out.println("MATHEMATICS: "+mat);
        System.out.println("SCIENCE: "+sci);
        System.out.println("SOCIAL SCIENCE: "+ssc);
        System.out.println("TOTAL: "+total);
        System.out.println("GRADE: "+calculate());
        System.out.println("STATUS: "+passFail());
    }
}

class Main{
    public static void main(String args[]){
        Marks obj = new Marks();
        obj.getMarks();
        obj.putMarks();
    }
}