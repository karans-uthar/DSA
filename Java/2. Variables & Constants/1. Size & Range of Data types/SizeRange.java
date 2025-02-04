public class SizeRange {
    public static void main(String[] args) {
        // Byte is a wrapper class corresponding to byte data type
        System.out.println("Size of byte: " + Byte.BYTES);
        System.out.println("Minimum value of byte: " + Byte.MIN_VALUE);
        System.out.println("Maximum value of byte: " + Byte.MAX_VALUE);

        // Short is a wrapper class corresponding to short data type
        System.out.println("Size of short: " + Short.BYTES);
        System.out.println("Minimum value of short: " + Short.MIN_VALUE);
        System.out.println("Maximum value of short: " + Short.MAX_VALUE);

        // Integer is a wrapper class corresponding to integer data type
        System.out.println("Size of integer: " + Integer.BYTES);
        System.out.println("Minimum value of integer: " + Integer.MIN_VALUE);
        System.out.println("Maximum value of integer: " + Integer.MAX_VALUE);

        // Float is a wrapper class corresponding to float data type
        System.out.println("Size of float: " + Float.BYTES);
        System.out.println("Minimum value of float: " + Float.MIN_VALUE);
        System.out.println("Maximum value of float: " + Float.MAX_VALUE);

        // Double is a wrapper class corresponding to double data type
        System.out.println("Size of double: " + Double.BYTES);
        System.out.println("Minimum value of double: " + Double.MIN_VALUE);
        System.out.println("Maximum value of double: " + Double.MAX_VALUE);

        System.out.println("Sum of " + 8 + " and " + 9 + " = " + Integer.sum(8, 9));
        System.out.println("Max of " + 8 + " and " + 9 + " = " + Integer.max(8, 9));
        System.out.println("Min of " + 8 + " and " + 9 + " = " + Integer.min(8, 9));
    }
}

// javap java.lang.Integer 
// javap java.lang.Short 
// javap java.lang.Byte 
// javap java.lang.Float 
// javap java.lang.Double 
// javap java.lang.Character 
// javap java.lang.Boolean 