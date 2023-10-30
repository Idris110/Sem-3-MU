#include <stdio.h>

int main()
{
    int i=0,dig,flag=0,bin,b[16];
    printf("\nEnter the binary number:");
    scanf("%d",&bin);
    while(bin!=0)
    {
        dig=bin%10;
        if(dig!=0 && dig!=1)
        {
        printf("The number entered is not a binary number\n"); 
        printf("Enter the correct number!\n");
        exit(0);
        }
        
        if(flag!=1) b[i]=dig;
        else
        {
            if(dig==0) b[i]=1;
            else b[i]=0;
        }
        if(dig==1) flag = 1;
        bin=bin/10;
        i++;
    }

    printf("The 2's Complement is :");
    for (i=i-1;i>=0;i--)
    {
        printf("%d",b[i]);
    }
    printf("\n");
    return 0;
} 