import java.util.Scanner;

public class Swap {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in))
        {
            // Variables
            int a, b;

            System.out.print("Enter a: "); a = sc.nextByte();
            System.out.print("Enter b: "); b = sc.nextByte();

            // Method 1: Using third variable
            System.out.println("\n-------------Method 1-------------");
            System.out.println("Before swapping: a = " + a + " and b = " + b);
            int temp;
            temp = a;
            a = b;
            b = temp;
            System.out.println("After swapping: a = " + a + " and b = " + b);

            // Method 2
            System.out.println("\n-------------Method 2-------------");
            System.out.println("Before swapping: a = " + a + " and b = " + b);
            a = a + b;
            b = a - b;
            a = a - b;
            System.out.println("After swapping: a = " + a + " and b = " + b);

            // Method 3 (Input non-zero values)
            System.out.println("\n-------------Method 3-------------");
            System.out.println("Before swapping: a = " + a + " and b = " + b);
            a = a * b;
            b = a / b;
            a = a / b;
            System.out.println("After swapping: a = " + a + " and b = " + b);

            // Method 4: Bit masking
            System.out.println("\n-------------Method 4-------------");
            System.out.println("Before swapping: a = " + a + " and b = " + b);
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
            System.out.println("After swapping: a = " + a + " and b = " + b);

            sc.close();
        }
    }
}
