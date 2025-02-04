public class Number {
    public static void main(String[] args) {
        // Integer literals
        System.out.println("10 = " + 10);
        System.out.println("012 = " + 012);
        System.out.println("0xA = " + 0xA); // 0XA or 0xa or 0Xa
        System.out.println("0b1010 = " + 0b1010); // 0B1010

        // long num1 = 99_99_999_; // illegal underscore
        // float num2 = 10_23_540.456; // lossy conversion from double to float 
        long num1 = 99_99_999;
        float num2 = 10_23_540.456F;
        System.out.println("num1 = " + num1);
        System.out.println("num2 = " + num2);
    }
}
