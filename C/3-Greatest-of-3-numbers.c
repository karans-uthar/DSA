#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Enter a: "); scanf("%d", &a);
    printf("Enter b: "); scanf("%d", &b);
    printf("Enter c: "); scanf("%d", &c);

    // Method 1
    printf("Greatest number is: ");
    if(a > b) {
        if (a > c) printf("%d", a);
        else printf("%d", c);
    }
    else {
        if (b > c) printf("%d", b);
        else printf("%d", c);
    }
    printf(" // Method 1\n");

    // Method 2: Ternary or Conditional Operator
    printf("Greatest number is: ");
    a>b ? a>c ? printf("%d", a) : printf("%d", c) : b>c ? printf("%d", b) : printf("%d", c);
    printf(" // Method 2\n");
}

/*
Note: Relate the evaluation of ternary operator to DYKE set and for every prefix of DYKE set number of '(' is greater than or equals to number of ')' 

CFG for DYKE set: S -> SS/(S)/ε
*/