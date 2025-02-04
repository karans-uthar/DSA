import java.util.Scanner;

public class Cuboid {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in))
        {
            // Variables
            int l, b, h; // l = length, b = breadth, h = height;
            int surfaceArea, volume;

            System.out.print("Enter the length of the cuboid: ");
            l = sc.nextInt();

            System.out.print("Enter the breadth of the cuboid: ");
            b = sc.nextInt();

            System.out.print("Enter the height of the cuboid: ");
            h = sc.nextInt();

            surfaceArea = 2*(l*b + l*h + b*h);
            volume = l*b*h;

            System.out.println("-----------------------------------------");
            System.out.println("Surface area of cuboid: " + surfaceArea + " square units");
            System.out.println("Volume of cuboid: " + volume + " cube units");

            sc.close();
        }
    }
}
