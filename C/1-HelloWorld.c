#include <stdio.h>
#include <string.h> // For strcspn

int main()
{
    // Variables
    int num1, num2, age;
    float weight;
    char fullName[100], purpose[100];

    printf("Hello World\n");

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (getchar() != '\n'); // if (getchar() == '\n'); 

    printf("Enter your full name: ");
    fgets(fullName, sizeof(fullName), stdin);

    fullName[strcspn(fullName, "\n")] = '\0';

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your weight: ");
    scanf("%f", &weight);

    printf("Enter your purpose: ");
    scanf("%s", purpose);

    printf("-----------------------------\n");

    printf("Sum of %d and %d = %d\n", num1, num2, (num1 + num2));
    printf("My name is %s\n", fullName);
    printf("My name is %d\n", age);
    printf("My name is %f\n", weight);
    printf("My name is %s\n", purpose);
}