#include <stdio.h>

int main()
{
    int dec,i,length,a[16];
    printf("\nEnter decimal Number : ");
    scanf("%d",&dec);
    for(i=0;dec!=0;i++)
    {
        a[i]=dec%2;
        dec=dec/2;
    }
    length=--i;
    printf("Binary equivalent : ");
    for(i=length;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}