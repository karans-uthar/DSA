public class Print {
    public static void main(String[] args) {
        int x = 10, y = 25;
        float f = 35.454f;
        double d = -0.0000343534534;
        String s = "Karan Suthar";

        System.out.printf("x = %d and y = %d\n", x, y);              // x = 10 and y = 25
        System.out.printf("x = %x and y = %o\n", x, y);              // x = a and y = 31
        System.out.format("x = %5d and y = %10d\n", x, y);           // x =    10 and y =         25
        System.out.printf("x = %-5d and y = %+10d\n", x, y);         // x = 10    and y =        +25
        System.out.printf("x = %05d and y = %(10d\n", x, -y);        // x =    10 and y =        (25)
        System.out.println("x = " + x + " and y = " + y);            // x = 10 and y = 25
        System.out.print("x = " + x + " and y = " + y + "\n");       // x = 10 and y = 25
        System.out.println("Sum = " + x + y + " is wrong");          // Sum = 1025 is wrong
        System.out.println(x + y + " = Sum is correct");             // 35 = Sum is correct
        System.out.println("Sum = " + (x + y) + " is correct");      // Sum = 35 is correct
        System.out.printf("f = %.3f and d = %f\n", f, d);            // f = 35.45 and d = -0.000034
        System.out.printf("f = %e and d = %e\n", f, d);              // f = 35.45 and d = -0.000034
        System.out.format("f = %g and d = %g\n", f, d);              // f = 35.4540 and d = -3.43535e-05
        System.out.printf("Mera naam: %s\n", s);                     // Mera naam: Karan Suthar
        System.out.format("%2$d, %1$d, %2$d, %2$d %1$d\n", 84, -73); // -73, 84, -73, -73 84
    }
}

/*
 * System.out.println();
 * System.out.print();
 * System.out.printf();
 * System.out.format();
 */

/* FORMAT: %[arguement_index$][flags][width][.precision]conversion
 * 
 * argument_index$ => 1$, 2$, 3$, etc...
 * flags           => '-', '+', '0', '', '('
 * width           =>
 * .precision      => 
 * conversion      => char(c), integegr(d, o, x), float(f, e, g), (String)s
 */