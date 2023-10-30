#include <stdio.h>

int main() {
    int a[20],elem,again,n,i,choice,j,temp;

    printf("Enter number of elements :");
    scanf("%d",&n);
    printf("Enter the elements :\n");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    do{
        printf("Enter your choice :\n1. search\t2. update\t3. insert\n4. delete\t5. sort in ascending order\t6. sort in decending order\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be searched :");
            scanf("%d",&elem);
            for(i=0;i<n;i++)
            {
                if(a[i]==elem) 
                {
                    printf("Index of required element is %d\n",i);
                    break;
                }
            }
            if(i==n) printf("Not found\n");
            break;
        
        case 2:
            printf("Enter the index of element to be updated :");
            scanf("%d",&i);
            printf("update %d with :",a[i]);
            scanf("%d",&elem);
            a[i]=elem;
            break;
        
        case 3:
            printf("Enter the index where element to be inserted :");
            scanf("%d",&j);
            printf("Enter the element to be inserted :");
            scanf("%d",&elem);
            for ( i = ++n; i > j; i--)
            {
                temp=a[i];
                a[i]=a[i-1];
                a[i-1]=temp;
            }
            a[j]=elem;
            break;
            
        case 4:
            printf("Enter the index of element to be deleted :");
            scanf("%d",&j);
            n--;
            for ( i = j; i < n; i++)
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
            break;

        case 5:
            printf("Sorting arrray in ascending order\n");
            for ( i = 0; i < n-1; i++)
            {
                for(j=0;j<n-i-1;j++)
                {
                    if(a[j]>a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
            break;

        case 6:
            printf("Sorting arrray in decending order\n");
            for ( i = 0; i < n-1; i++)
            {
                for(j=0;j<n-i-1;j++)
                {
                    if(a[j]<a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
            break;

        default:
            printf("Invalid Choice !\n");
        }
    printf("\nNew array : ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
        
    printf("\nIf you want to traversal again enter 1 either 0 : ");
    scanf("%d",&again);
    }while(again==1);
}
