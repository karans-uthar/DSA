#include <stdio.h>

int main()
{
    // CONCEPT 1
    float x = 3.4; // x = 3.399999 <- 3.3999999999999
    int y = (x == 3.4); // or y = x == 3.4;
    printf("%d\n", y); // 0
    /*
    x = 3.399999
    3.399999 == 3.3999999999999
    */

    // CONCEPT 2
    x = 3.5; // x = 3.500000 <- 3.5000000000000
    y = (x == 3.5);
    printf("%d\n", y); // 1
    /*
    x = 3.500000
    3.500000 == 3.5000000000000
    */

    // CONCEPT 3
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("sizeof(float) = %ld\n", sizeof(3.4f));
    printf("sizeof(double) = %ld\n", sizeof(3.4));
    printf("sizeof(char) = %ld\n", sizeof(char));
    printf("sizeof(long) = %ld\n", sizeof(long));
    printf("sizeof(short) = %ld\n", sizeof(short));

    // CONCEPT 4
    int z = 5;
    printf("sizeof(z) = %ld\n", sizeof(z++));
    printf("sizeof(z) = %ld\n", sizeof(++z));
    printf("z = %d\n", z);
    // sizeOf() is an operator and not a function so it doen't evaluate the expression
}