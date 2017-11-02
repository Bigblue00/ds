#include<stdio.h>

void quicksort(int ,int );
int partition(int ,int );

int a[100];

int main()
{
 int n,i,j;
 printf("enter the size of the array \n");
 scanf("%d",&n);
 printf("enter the array \n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);

 quicksort(0,n-1);

 printf("the sorted array is \n");
 for(i=0;i<n;i++)
 printf("%d   ",a[i]);
 
return(0);
}

void quicksort(int p,int q)
{
 int mid=(p+q)/2;
 int j;
   if(p<q)
     {
     
      j=partition(p,q);
      quicksort(p,j-1);
      quicksort(j+1,q);
 
     }

}

int partition(int beg,int end)
{
  int pivot=a[beg];
  int i=beg,j=end,temp;
   int b[100];
 
   while(i<=j)
  {
   while((a[i]<=pivot)&&(i<=end))
   i++;
      
   while((a[j]>pivot)&&(j>=beg))
   j--;
  
    if(i<j)
    {
     temp=a[i];
     a[i]=a[j];
      a[j]=temp;
    }
                   
  }

  temp=a[beg];
  a[beg]=a[j];
  a[j]=temp;


return(j);
}























  
