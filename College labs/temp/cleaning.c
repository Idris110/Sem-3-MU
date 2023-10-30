#include <stdio.h>
//#include <stdlib.h>
#include <stdlib.h>
int main(void) {
	int t,n,m,i,j,done,dec,as[1000];
	//printf("m\n");
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
        dec=0;
        
        scanf("%d%d",&n,&m);
        int *a=(int*)malloc(n*sizeof(int));
        for(i=1;i<=n;i++) a[i]=1;
        
        for(i=1;i<=m;i++)
        {
        scanf("%d",&done);
        a[done]=0;
        }
        
        for(i=1;i<=n;i++)
        {
        if(a[i]==1)
        {
            if(dec%2==0) printf("%d ",i);
            else as[dec]=i;
            dec++;
        }
        }
        printf("\n");
        for ( i = 1; i < dec; i=i+2)
        {
            printf("%d",as[i]);
        }
        printf("\n");
	} 
	return 0;
}