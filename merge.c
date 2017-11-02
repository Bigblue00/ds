#include<stdio.h>

void Merge(int beg,int end);
void Mergesort(int p,int q);

int a[100];

int main()
{
 int n,i;
 printf("enter the size of the array \n");
 scanf("%d",&n);
 printf("enter the array \n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);

 Mergesort(0,n-1);

 printf("the sorted array is \n");
 for(i=0;i<n;i++)
 printf("%d   ",a[i]);
 
return(0);
}

void Mergesort(int p,int q)
{
 int mid=(p+q)/2;
  
   if(p<q)
     {
     
      Mergesort(p,mid);
      Mergesort(mid+1,q);
      Merge(p,q);
     }

}


void Merge(int beg,int end)
{
  int mid=(beg+end)/2;
  int i=beg,j=mid+1,k=0;
   int b[100];
 
   while((i<=mid)&&(j<=end))
     {
        if(a[i]<a[j])
           {
             b[k]=a[i];
             i++;
      
           }
        else
           {
             b[k]=a[j];
             j++;

           }
     k++;
     }
  while(i<=mid)
    {
       b[k]=a[i];
       
       i++;
       k++;

    }

   while(j<=end)
    {
       b[k]=a[j];
      
       j++;
        k++;
    }
   
 for(i=beg;i<=end;i++)
  {
   a[i]=b[i-beg];
  }



}























