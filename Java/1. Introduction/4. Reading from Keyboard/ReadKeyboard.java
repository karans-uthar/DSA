// import java.lang.*;
import java.util.*;

class ReadKeyboard 
{
    public static void main(String[] args) 
    {
        try (Scanner s = new Scanner(System.in)) 
        {
            // Variables
            String fullName, purpose, gender;
            int num1, num2, age;
            float weight;

            System.out.print("Enter your name: ");
            fullName = s.nextLine();
            
            System.out.print("Enter your purpose: ");
            purpose = s.next();
            
            System.out.print("Enter two numbers: ");
            num1 = s.nextInt();
            num2 = s.nextInt();
            
            System.out.print("Enter your age: ");
            age = s.nextByte();
            
            System.out.print("Enter your gender: ");
            gender = s.next();

            System.out.print("Enter your weight: ");
            weight = s.nextFloat();
            
            System.out.println("--------------------------");

            System.out.println("My name is " + fullName);
            System.out.println("My purpose is " + purpose);
            System.out.println("Sum of " + num1 + " and " + num2 + " = " + (num1 + num2));
            System.out.println("My age is " + age);
            System.out.println("My gender is " + gender);
            System.out.println("My weight is " + weight);
        }
    }
}