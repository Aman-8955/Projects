#include <stdio.h>
#include <math.h>
unsigned long long int deci_to_bai(unsigned long long int num)
{
    unsigned long long int result = 0;
    int i, rem, binary[80];
    for (i = 0; num != 0; i++)
    {
        rem = num % 2;
        num = num / 2;
        binary[i] = rem;
    }
    for (i = i - 1; i >= 0; i--)
    {
        result = (result * 10) + binary[i];
    }
    return result;
}
unsigned long long int deci_to_octal(unsigned long long int num)
{
    int rem, octal[80], i;
    unsigned long long int result = 0;
    for (i = 0; num != 0; i++)
    {
        rem = num % 8;
        num = num / 8;
        octal[i] = rem;
    }
    for (i = i - 1; i >= 0; i--)
    {
        result = (result * 10) + octal[i];
    }
    return result;
}
unsigned long long int bai_to_deci(unsigned long long int num)
{
    int i, rem;
    unsigned long long int result = 0;
    for (int i = 0; num != 0; i++)
    {
        rem = num % 10;
        num = num / 10;
        result = result + rem * pow(2, i);
    }
    return result;
}
unsigned long long int octal_to_deci(unsigned long long int num)
{
    int rem, i;
    unsigned long long int result = 0;
    for (int i = 0; num != 0; i++)
    {
        rem = num % 10;
        num = num / 10;
        result = result + rem * pow(8, i);
    }
    return result;
}
void main()
{
    int choice, choice2;
    unsigned long long int num, tmpnum;
    printf("1.Decimal\n2.Binary\n3.Octal\n");
    printf("Enter your number according to your choice:- ");
    scanf("%d", &choice);
    printf("TO\n");
    printf("1.Decimal\n2.Binary\n3.Octal\n");
    printf("Enter your number according to your choice:- ");
    scanf("%d", &choice2);
    switch (choice)
    {
    case 1:
        switch (choice2)
        {
        case 1:
            printf("Enter your Decimal number:- ");
            scanf("%lld", &num);
            printf("Decimal = %lld", num);
            break;
        case 2:
            printf("Enter your Decimal number:- ");
            scanf("%lld", &num);
            printf("Binary = %lld", deci_to_bai(num));
            break;
        case 3:
            printf("Enter your Decimal number:- ");
            scanf("%lld", &num);
            printf("Octal = %lld", deci_to_octal(num));
            break;
        }
        break;
    case 2:
        switch (choice2)
        {
        case 1:
            printf("Enter your Binary number:- ");
            scanf("%lld", &num);
            printf("Decimal = %lld", bai_to_deci(num));
            break;
        case 2:
            printf("Enter your Binary number:- ");
            scanf("%lld", &num);
            printf("Binary = %lld", num);
            break;

        case 3:
            printf("Enter your Binary number:- ");
            scanf("%lld", &num);
            tmpnum = bai_to_deci(num);
            printf("Octal = %lld", deci_to_octal(tmpnum));
            break;
        }
        break;
    case 3:
        switch (choice2)
        {
        case 1:
            printf("Enter your Octal number:- ");
            scanf("%lld", &num);
            printf("Decimal = %lld", octal_to_deci(num));
            break;
        case 2:
            printf("Enter your Octal number:- ");
            scanf("%lld", &num);
            tmpnum = octal_to_deci(num);
            printf("Binary = %lld", deci_to_bai(tmpnum));
            break;
        case 3:
            printf("Enter your Octal number:- ");
            scanf("%lld", &num);
            printf("Octal = %lld", num);
            break;
        }
        break;
    }
}
