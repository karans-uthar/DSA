#include <stdio.h>

int main()
{
    int a, b, c, d;

    printf("Enter a: "); scanf("%d", &a);
    printf("Enter b: "); scanf("%d", &b);
    printf("Enter c: "); scanf("%d", &c);
    printf("Enter d: "); scanf("%d", &d);

    // Method 1
    printf("Smallest number is: ");
    if(a < b)
    {
        if(a < c) 
        {
            if (a < d) printf("%d", a);
            else printf("%d", d);
        }
        else 
        {
            if (c < d) printf("%d", c);
            else printf("%d", d);
        }
    }
    else 
    {
        if(b < c)
        {
            if (b < d) printf("%d", b);
            else printf("%d", d);
        }
        else
        {
            if (c < d) printf("%d", c);
            else printf("%d", d);
        }
    }
    printf(" // Method 1\n");

    // Method 2: Ternary or Conditional Operator
    printf("Smallest number is: ");
    a<b ? a<c ? a<d ? printf("%d", a) : printf("%d", d) : c<d ? printf("%d", c) : printf("%d", d) : b<c ? b<d ? printf("%d", b) : printf("%d", d) : c<d ? printf("%d", c) : printf("%d", d);
    printf(" // Method 2\n");
}