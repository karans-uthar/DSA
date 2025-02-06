// import java.lang.*;
import java.util.Scanner;

public class Equation {
    public static void main(String[] args) 
    {
        try (Scanner sc = new Scanner(System.in)) 
        {
            // Variables
            int a, b, c;
            float r1, r2, D;

            System.out.print("Enter a, b, c: ");

            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();

            D = b*b - 4*a*c;

            System.out.println("Equation: " + a + "x² + " + b + "x + " + c + " = 0");
            System.out.println("Value of D = " + D);
            System.out.println("----------------------------");
            
            if (D < 0) System.out.println("No real roots exist for the given equation");
            else {
                r1 = (-b + (float)Math.sqrt(D)) / (4*a);
                r2 = (-b - (float)Math.sqrt(D)) / (4*a);
                
                System.out.println("Roots of the given equation are r1 = " + r1 + ", r2 = " + r2);
            }
        }
    }
}
