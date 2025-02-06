public class WN {
    public static void main(String[] args) {
        byte b = 10;
        short s = 15;
        int i = 250;
        long l = 1289;
        float f = 54.6f;
        double d = 343.534;
        boolean B = false;
        char c = 'A'; // or char c = 65
        String S = "Karan Suthar";

        /*
        b = s; // incompatible types: possible lossy conversion from short to byte
        b = i; // incompatible types: possible lossy conversion from int to byte
        b = l; // incompatible types: possible lossy conversion from long to byte
        b = f; // incompatible types: possible lossy conversion from float to byte
        b = d; // incompatible types: possible lossy conversion from double to byte
        b = B; // Type mismatch: boolean cannot be converted to byte
        b = c; // incompatible types: possible lossy conversion from char to byte
        b = S; // Type mismatch: String cannot be converted to byte
        */

        /*
        s = b; 
        s = i; // incompatible types: possible lossy conversion from int to short
        s = l; // incompatible types: possible lossy conversion from long to short
        s = f; // incompatible types: possible lossy conversion from float to short
        s = d; // incompatible types: possible lossy conversion from double to short
        s = B; // Type mismatch: boolean cannot be converted to short
        s = c; // incompatible types: possible lossy conversion from char to short
        s = S; // Type mismatch: String cannot be converted to short
        */

        /*
        i = b; 
        i = s; 
        i = l; // incompatible types: possible lossy conversion from long to int
        i = f; // incompatible types: possible lossy conversion from float to int
        i = d; // incompatible types: possible lossy conversion from double to int
        i = B; // Type mismatch: boolean cannot be converted to int
        i = c;
        i = S; // Type mismatch: String cannot be converted to int
        */

        /*
        l = b; 
        l = s; 
        l = i; 
        l = f; // incompatible types: possible lossy conversion from float to long
        l = d; // incompatible types: possible lossy conversion from double to long
        l = B; // Type mismatch: boolean cannot be converted to long
        l = c;
        l = S; // Type mismatch: String cannot be converted to long
        */

        /*
        f = b; 
        f = s; 
        f = i; 
        f = l; 
        f = d; // incompatible types: possible lossy conversion from double to float
        f = B; // Type mismatch: boolean cannot be converted to float
        f = c;
        f = S; // Type mismatch: String cannot be converted to float
        */

        /*
        d = b; 
        d = s; 
        d = i; 
        d = l; 
        d = f; 
        d = B; // Type mismatch: boolean cannot be converted to double
        d = c;
        d = S; // Type mismatch: String cannot be converted to double
        */

        /*
        B = b; // Type mismatch: byte cannot be converted to boolean
        B = s; // Type mismatch: short cannot be converted to boolean
        B = i; // Type mismatch: int cannot be converted to boolean
        B = l; // Type mismatch: long cannot be converted to boolean
        B = f; // Type mismatch: float cannot be converted to boolean
        B = d; // Type mismatch: double cannot be converted to boolean
        B = c; // Type mismatch: char cannot be converted to boolean
        B = S; // Type mismatch: String cannot be converted to boolean
        */

        /*
        c = b; // incompatible types: possible lossy conversion from byte to char
        c = s; // incompatible types: possible lossy conversion from short to char
        c = i; // incompatible types: possible lossy conversion from int to char
        c = l; // incompatible types: possible lossy conversion from long to char
        c = f; // incompatible types: possible lossy conversion from float to char
        c = d; // incompatible types: possible lossy conversion from double to char
        c = B; // Type mismatch: boolean cannot be converted to char
        c = S; // Type mismatch: String cannot be converted to char
        */

        /*
        S = b; // Type mismatch: byte cannot be converted to String
        S = s; // Type mismatch: short cannot be converted to String
        S = i; // Type mismatch: int cannot be converted to String
        S = l; // Type mismatch: long cannot be converted to String
        S = f; // Type mismatch: float cannot be converted to String
        S = d; // Type mismatch: double cannot be converted to String
        S = B; // Type mismatch: boolean cannot be converted to String
        S = c; // Type mismatch: char cannot be converted to String
        */

        System.out.println(b);
        System.out.println(s);
        System.out.println(i);
        System.out.println(l);
        System.out.println(f);
        System.out.println(d);
        System.out.println(B);
        System.out.println(c);
        System.out.println(S);
    }
}

/*
 * Widening = Upcasting (implicit)
 * Narrowing = Downcasting (explicit)
 */