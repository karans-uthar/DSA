#include <stdio.h>

int main()
{
    // Variables
    int num, sum = 0, temp;

    printf("Enter a non-negative number: ");
    scanf("%d", &num);

    // LOGIC
    temp = num;

    while (temp != 0)
    {
        sum = sum + (temp % 10);
        temp = temp / 10;
    }

    printf("Sum of digits of number %d = %d\n", num, sum);
}