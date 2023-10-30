#include <stdio.h>

int main() {
    int bin,dec=0,pow=1;
    printf("\nEnter a binary number: ");
    scanf("%d", &bin);
    while(bin!=0)
    {
        dec=dec+pow*(bin%10);
        pow=pow*2;
        bin=bin/10;
    }
    printf("Decimal equivalent is : %d\n",dec);
}
