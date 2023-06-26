import java.util.*;

class Main{
    public static void main(String args[]){
        int n1, n2, result, op;
        Scanner sc=new Scanner(System.in);
        
        do{
            System.out.println("Enter operation you wish to print ");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Exit");
            
            op=sc.nextInt();
            switch(op){
                case 1:
                    System.out.println("Enter numbers: ");
                    n1=sc.nextInt();
                    n2=sc.nextInt();
                    result=n1+n2;
                    System.out.println("Sum is "+result);
                    break;
                case 2:
                    System.out.println("Enter numbers: ");
                    n1=sc.nextInt();
                    n2=sc.nextInt();
                    result=n1-n2;
                    System.out.println("Difference is "+result);
                    break;
                case 3:
                    System.out.println("Enter numbers: ");
                    n1=sc.nextInt();
                    n2=sc.nextInt();
                    result=n1*n2;
                    System.out.println("Product is "+result);
                    break;
                case 4:
                    System.out.println("Enter numbers: ");
                    n1=sc.nextInt();
                    n2=sc.nextInt();
                    result=n1/n2;
                    System.out.println("Quotient is "+result);
                    break;
                case 5:
                    break;
                default:
                    System.out.println("Not valid!");
                    break;
            }
        }while(op!=0);
        
    }
}