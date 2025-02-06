public class Bitwise {
    public static void main(String[] args) {
        int x = 0b011011; // 27 in decimal
        int y = 075; // 61 in decimal
        int z = 0xFFffFFD4; // -44 in decimal
        int t = -0b1010; // -10 in decimal

        System.out.println("x in binary = " + Integer.toBinaryString(x));
        System.out.println("x in decimal = " + x);
        System.out.println("y in octal = " + Integer.toOctalString(y));
        System.out.println("y in decimal = " + y);
        System.out.println("z in hexadecimal = " + Integer.toHexString(z));
        System.out.println("z in decimal = " + z);
        System.out.println("t in binary = " + Integer.toBinaryString(t));
        System.out.println("t in decimal = " + t);

        System.out.println("-------------");
        System.out.println("x AND y = " + (x&y));
        System.out.println("x AND z = " + (x&z));
        System.out.println("y AND z = " + (y&z));

        System.out.println("-------------");
        System.out.println("x OR y = " + (x|y));
        System.out.println("x OR z = " + (x|z));
        System.out.println("y OR z = " + (y|z));

        System.out.println("-------------");
        System.out.println("x XOR y = " + (x^y));
        System.out.println("x XOR z = " + (x^z));
        System.out.println("y XOR z = " + (y^z));

        System.out.println("-------------");
        System.out.println("x << 1 = " + (x<<1));
        System.out.println("y << 2 = " + (y<<2));
        System.out.println("z << 3 = " + (z<<3));

        System.out.println("-------------");
        System.out.println("x >> 1 = " + (x>>1));
        System.out.println("y >> 2 = " + (y>>2));
        System.out.println("z >> 3 = " + (z>>3));

        System.out.println("-------------");
        System.out.println("t >> 1 = " + (t>>1));
        System.out.println("t << 1 = " + (t<<1));
        System.out.println("t >>> 1 = " + (t>>>1));

        System.out.println("------------------------------------------");
        // System.out.println("t >> 1 = " + Integer.toBinaryString(t));
        System.out.println("t >> 1 = " + String.format("%s", Integer.toBinaryString(t>>1)));
        System.out.println("t << 1 = " + String.format("%s", Integer.toBinaryString(t<<1)));
        System.out.println("t >>> 1 = " + String.format("%32s", Integer.toBinaryString(t>>>1)));

        System.out.println("-------------------------------------------");
        System.out.println("~x = " + String.format("%s", Integer.toBinaryString(~x)) + " = " + (~x));
        System.out.println("~y = " + String.format("%s", Integer.toBinaryString(~y)) + " = " + (~y));
        System.out.println("~z = " + String.format("%32s", Integer.toBinaryString(~z)) + " = " + (~z));
    }
}
