#include <stdio.h>

void celebrity(int n,int p,int a[n][2],int c[p])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(a[i][0]!=a[i][1])		
		c[a[i][0]]=0;
	}	

}

int main()
{
	int n,p;
	printf("Enter No. of persons\n");
	scanf("%d",&p);
	printf("Enter No. of relations\n");
	scanf("%d",&n);
	int a[n][2],i,j,c[p];
	for(i=0;i<n;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<p;i++)
		c[i]=1;
	celebrity(n,p,a,c);
	for(i=0;i<p;i++)
		if(c[i]==1)
		{
			printf("Person %d is celebrity\n",i);
			return 0;
		}
	printf("No Celebrity exists\n");
	

	return(0);
}
