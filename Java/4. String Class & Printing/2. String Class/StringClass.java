// import java.lang.*;

public class StringClass {
    public static void main(String[] args) {
        char c[] = {'A', 66, 'C', 'D'};
        byte b[] = {65, 66, 'C', 68};
        String s1 = "ABCD"; // String object "ABCD" will be created inside a pool 
        String s2 = "ABCD"; // String object "ABCD" is already created inside a pool, only reference to that object will pass to variable s2

        String str1 = new String(c);
        String str2 = new String(b);
        // String str = new String("Karan"); // You are trying to create object "Karan" in both pool and heap

        System.out.printf("str1 = %s\n", str1);
        System.out.printf("str2 = %s\n", str2);
        System.out.printf("s1 = %s\n", s1);
        System.out.printf("s2 = %s\n", s2);

        String str3 = new String(c, 1, 2);
        System.out.println("str3 = " + str3);

        // System.out.println(s1 == s2); // true 
        //String str = new String("ABCD");
        // System.out.println(s1 == str); // false
    }
}

/*
 * Constructors:
 *             1. String (char [])
 *             2. String (byte [])
 *             3. String (String)
 */