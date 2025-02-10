#include <stdio.h>

int main()
{
    // Vaiables
    int num, rev = 0, temp, rem;

    printf("Enter a number: ");
    scanf("%d", &num);

    // LOGIC
    temp = num;

    while (temp != 0)
    {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }

    printf("Reverse of number %d = %d\n", num, rev);
}