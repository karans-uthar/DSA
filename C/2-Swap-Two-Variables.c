#include <stdio.h>

/* Incorrect Way (Call by Value)
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/

// Correct Way (Call by Reference)
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Incorrect Way (Call by Reference) because only addresses are swapping not actual value
void swap(int *a, int *b)
{
    int *temp;
    temp = a;
    a = b;
    b = temp;
}
*/

int main()
{
    int a = 5, b = -6;
    
    /* Incorrect Way (Call by Value)
    printf("Before swapping, a = %d and b = %d\n", a, b);
    swap(a, b);
    printf("After swapping, a = %d and b = %d\n", a, b);
    */

    // Correct Way (Call by Reference)
    printf("Before swapping, a = %d and b = %d\n", a, b);
    swap(&a, &b);
    printf("After swapping, a = %d and b = %d\n", a, b);

    printf("----------------------------------\n");

    // Swapping two variables without third variable
    printf("Before swapping, a = %d and b = %d\n", a, b);
    a = a + b; // a * b 
    b = a - b; // a / b 
    a = a - b; // a / b  
    printf("After swapping, a = %d and b = %d\n", a, b);
}