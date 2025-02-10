// comma is used as an operator (expression) or seperator (function calls, function declaration, function defination, etc.)

#include <stdio.h>

int main()
{
    // int x = 5; // error because here comma is used as an seperator
    int x, y;

    // CONCEPT 1
    x = 5, 6, 7; // no error because here comma is used as an operator
    printf("x = %d\n", x); // x = 5

    y = x = 5, 6, 7;
    printf("x = %d\n", x); // x = 5
    printf("y = %d\n", y); // y = 5

    // CONCEPT 2
    x = (5, 6, 7);
    printf("x = %d\n", x); // x = 7

    x = (5 + 6, 5 / 6, 5 * 6);
    printf("x = %d\n", x); // x = 30

    y = (x = 5, 6, 7);
    printf("x = %d\n", x); // x = 5
    printf("y = %d\n", y); // x = 7
}