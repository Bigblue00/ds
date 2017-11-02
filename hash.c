#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node
{
 int data;
 struct node *nptr;

};

struct node *A[SIZE]={NULL};

int hashfunction(int k);
void insert(int k,int hk);
void delete(int k,int hk);
void search(int k,int hk);
void print(void);

int main()
{
 int n,k;
 
 do
 {
    printf("\n1.insert \n2.delete \n3.search \n4.display \n5.exit \nchoose one option");
    scanf("%d",&n);
    
    if(n==1)
    {
      printf("\n enter the key to be inserted:");
      scanf("%d",&k);
      insert(k,hashfunction(k));
    }

   if(n==2)
    {
      printf("\n enter the key to be deleted:");
      scanf("%d",&k);
      delete(k,hashfunction(k));
    }

   if(n==3)
    {
      printf("\n enter the key to be searched:");
      scanf("%d",&k);
      search(k,hashfunction(k));
    }

   
   if(n==4)
    {
      print();
      
    }
 
 }while(n!=5);

return(0);
}

int hashfunction(int k)
{
  return(k%10);
}

void insert(int k,int hk)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=k;
  temp->nptr=A[hk];
  A[hk]=temp;
  return;

}


void delete(int k,int hk)
{
  struct node *ptr,*pptr;
  ptr=A[hk];
  
  while(ptr!=NULL)
    {
      if(ptr->data==k)
      break;
 
      pptr=ptr;
      ptr=ptr->nptr;

    }
  if(ptr==NULL)
    {
      printf(" \n entered key is not present ");
      return;

    }
  if(ptr==A[hk])
    {
      A[hk]=ptr->nptr;
      
    } 
  else
    {
      pptr->nptr=ptr->nptr;
    } 
  
 return;
}
 

void search(int k,int hk)
{
  int flag=0;
  struct node *ptr;
  ptr=A[hk];
  
  if(ptr==NULL)
   {
     printf("\n entered key is not present");

   }
  while(ptr!=NULL)
   {
     if(ptr->data==k)
      {
        flag=1;
        break;
      }
    ptr=ptr->nptr;
   }
  if(flag==1)
   {
      printf(" \n entered key is present");

   } 
  if(flag==0)
   {
      printf(" \n entered key is not present");

   }
return;
}



void print(void)
{
 int i;
 printf("h(k)   k \n");
 
 for(i=0;i<SIZE;i++)
   { 
     printf("%d     ",i);
      if(A[i]!=NULL)
        {
          struct node *ptr=A[i];
          while(ptr!=NULL)
           {
            printf("   %d",ptr->data);
            ptr=ptr->nptr;
           }
        }
      printf("\n");
   }
return;

}


























