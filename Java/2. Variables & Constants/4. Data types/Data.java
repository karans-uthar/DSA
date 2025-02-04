

public class Data {
    public static void main(String[] args) {
        byte b = 27;
        short s = 274;
        int i1 = 201, i2 = -201;
        long l = 2455993530l;
        float f = 335.3453F;
        double d = 4355.3564564;
        char c = 65;
        Boolean B = true;
        String S = "Karan Suthar";

        System.out.println(Byte.SIZE); // 8
        System.out.println(Byte.BYTES); // 1
        System.out.println(Byte.toString(b)); // 27
        
        System.out.println(Short.SIZE); // 16
        System.out.println(Short.BYTES); // 2
        System.out.println(s); // 274
        
        System.out.println(Integer.SIZE); // 32
        System.out.println(Integer.BYTES); // 4
        System.out.println(Integer.toBinaryString(i1)); // 11001001
        System.out.println(Integer.toOctalString(i1)); // 311
        System.out.println(Integer.toHexString(i1)); // c9
        System.out.println(Integer.toBinaryString(i2)); // 11111111111111111111111100110111
        System.out.println(Integer.toOctalString(i2)); // 37777777467
        System.out.println(Integer.toHexString(i2)); // ffffff37

        System.out.println(Long.SIZE); // 64
        System.out.println(Long.BYTES); // 8
        System.out.println(Long.toBinaryString(l)); // 10010010011000110111110010111010
        System.out.println(Long.toOctalString(l)); // 22230676272
        System.out.println(Long.toHexString(l)); // 92637cba

        System.out.println(Float.SIZE); // 32
        System.out.println(Float.BYTES); // 4
        System.out.println(Float.toString(f)); // 335.3453

        System.out.println(Double.SIZE); // 64
        System.out.println(Double.BYTES); // 8
        System.out.println(Double.toString(d)); // 4355.3564564

        System.out.println(Character.SIZE); // 16
        System.out.println(Character.BYTES); // 2
        System.out.println(Character.toString(c)); // A

        System.out.println(Boolean.TRUE); // true
        System.out.println(Boolean.FALSE); // false
        System.out.println(B); // true

        System.out.println(S); // Karan Suthar
    }
}
