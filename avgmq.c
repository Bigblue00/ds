#include<stdio.h>
#include<stdlib.h>

int a[100],b[100],c[100];
int nm=0,nq=0;

void quicksort(int p,int q);
int partition(int beg,int end);

void Merge(int beg,int end);
void Mergesort(int p,int q);

int main()
{
  int n,i,j=0;
  srand(time(NULL));
  
  while(j<1000)
  {
  
    for(i=0;i<100;i++)
     {
       a[i]=rand()%200;
       c[i]=a[i];
     }
     Mergesort(0,99);
     quicksort(0,99);
     j++;

   }

 printf("\n avg no. of comp(MS):%d",nm/1000);
 printf("\n avg no. of comp(QS):%d",nq/1000);


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
     nm++;
     }
  while(i<=mid)
    {
      b[k]=a[i];
       
       i++;
       k++;
       nm++;

    }

   while(j<=end)
    {
       b[k]=a[j];
      
       j++;
        k++;
       nm++;
    }
   
 for(i=beg;i<=end;i++)
  {
   a[i]=b[i-beg];
  }

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
   {
    i++;
   nq++;
   }
      
   while((a[j]>pivot)&&(j>=beg))
   {
    j--;
    nq++;
    }
  
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























