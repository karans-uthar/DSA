// import java.lang.*;
import java.util.Scanner;

public class Triangle 
{
    public static void main(String[] args) 
    {
        try (Scanner sc = new Scanner(System.in)) 
        {
            // Variables
            float base, height, area;
            float a, b, c, s; // a, b, c = sides of triangle and s = semi perimeter of triangle

            System.out.print("Enter base of the triangle: ");
            base = sc.nextFloat();

            System.out.print("Enter height of the triangle: ");
            height = sc.nextFloat();

            area = 0.5f * base * height;

            System.out.println("Area of triangle having base = " + base + " and height = " + height + " = " + area);

            System.out.println("-----------------------------------------------------------");

            System.out.print("Enter three sides of a triangle: ");
            a = sc.nextFloat();
            b = sc.nextFloat();
            c = sc.nextFloat();

            s = (a + b + c) / 2; // semi perimeter

            area = (float)Math.sqrt(s * (s - a) * (s - b) * (s - c));

            System.out.println("Area of triangle having sides as " + a + ", " + b + " and " + c + " = " + area);
        }
    }
}
