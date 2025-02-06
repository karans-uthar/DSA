public class IncDec {
    public static void main(String[] args) {
        // Variables
        int x = 5, y = 6;
        
        // INCREMENT OPERATOR
        x++; // or ++x;
        System.out.println(x); // 6

        ++y; // or y++;
        System.out.println(y); // 7

        x = y++; // x = y then increment y
        System.out.println(x + ", " + y); // 7, 8

        x = ++y; // increment y then x = y
        System.out.println(x + ", " + y); // 9, 9

        // DECREMENT OPERATOR
        x--; // or --x;
        System.out.println(x); // 8

        --y; // or y--;
        System.out.println(y); // 8

        x = y--; // x = y then decrement y
        System.out.println(x + ", " + y); // 8, 7

        x = --y; // decrement y then x = y
        System.out.println(x + ", " + y); // 6, 6
    }
}
