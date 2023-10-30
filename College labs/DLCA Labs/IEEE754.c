#include <stdio.h>

int binary(int n, int i)
{
    int k;
    for (i--; i >= 0; i--)
    {
        k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}

typedef union
{
    float f;
    struct
    {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } field;
} myfloat;

int main()
{
    myfloat var;
    printf("Enter any float number: ");
    scanf("%f", &var.f);
    printf("%d ", var.field.sign);
    binary(var.field.exponent, 8);
    printf(" ");
    binary(var.field.mantissa, 23);
    printf("\n");
    return 0;
}