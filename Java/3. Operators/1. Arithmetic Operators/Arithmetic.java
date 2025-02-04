public class Arithmetic {
    public static void main(String[] args) {
        int num1 = 14, num2 = 5;

        int add = num1 + num2;
        int sub = num1 - num2;
        int mul = num1 * num2;
        int div = num1 / num2;

        System.out.println(add); // 19
        System.out.println(sub); // 9
        System.out.println(mul); // 70
        System.out.println(div); // 2

        System.out.println(10/3); // 3
        System.out.println((10/3.0)); // 3.3333333333333335
        System.out.println((10.0/3)); // 3.3333333333333335
        System.out.println((10.0/3.0)); // 3.3333333333333335
        System.out.println((double)10/3); // 3.3333333333333335
        System.out.println((double)(10/3)); // 3.0
        System.out.println((float)10/3); // 3.3333333
        System.out.println((float)(10/3)); // 3.0

        System.out.println(11%3); // 2
        System.out.println(-11%3); // -2
        System.out.println(11%-3); // 2
        System.out.println(-11%-3); // -2
        System.out.println(11%3.2); // 1.3999999999999995
        System.out.println(11%3.2f); // 1.3999999
        System.out.println(11.2%3); // 2.1999999999999993
        System.out.println(11.2f%3); // 2.1999998
        System.out.println(11.2f%3.2); // 1.5999998092651362
        System.out.println(11.2%3.2f); // 1.5999998569488518
        System.out.println(11.2f%3.2f); // 1.5999997
        System.out.println(-11.2f%3.2f); // -1.5999997
        System.out.println(11.2f%-3.2f); // 1.5999997
        System.out.println(-11.2f%-3.2f); // -1.5999997

        System.out.println(3*4); // 12
        System.out.println(3*4.3); // 12.899999999999999
        System.out.println(4.3*3); // 12.899999999999999
        System.out.println(3*4.3f); // 12.900001
        System.out.println(4.3f*3); // 12.900001
    }
}
