#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;

};


struct node* insert(struct node *hptr,int );
void display(struct node *);
struct node * add(struct node *a,struct node *b,struct node *c);
struct node *ins(struct node *,int );
struct node *mul(struct node *a,struct node *b,struct node *c,int p,int q);
struct node *reverse(struct node *a);


int main()
{
 struct node *hptr1=NULL;
 struct node *hptr2=NULL;
 struct node *hptr3=NULL;
 struct node *hptr4=NULL;

 int m,n;
 printf("\nenter the degree of 1st poly:");
 scanf("%d",&n);
 hptr1=insert(hptr1,n);

 printf("\n enter the degree of 2nd poly:");
 scanf("%d",&m);
 hptr2=insert(hptr2,m);
 
 printf("\nthe first polynomial is:");
 display(hptr1);
 
 printf("\nthe second polynomial is:");
 display(hptr2);
 
  hptr3=add(hptr1,hptr2,hptr3);
  printf("\nThe sum of the polynomials is ");
  display(hptr3);
   
  hptr2=reverse(hptr2);
  hptr4=mul(hptr1,hptr2,hptr4,n,m);
  printf("\nThe product of the polynomials is ");
  display(hptr4);
 
  return(0);
 
}


 struct node * insert(struct node *hptr,int q)
{
	int x,i;
	struct node *thptr=hptr;
	for(i=0;i<=q;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter the coefficient: ");
		scanf("%d",&x);
		if(hptr==NULL)
		{
			temp->data=x;
			hptr=temp;
			hptr->next=NULL;
		}
		else
		{
			temp->data=x;
			while(thptr->next!=NULL)
			thptr=thptr->next;
			thptr->next=temp;
			temp->next=NULL;
		}
		thptr=hptr;
	}
		return(hptr);
}



void display(struct node *hptr)
{
	int i=0;
	struct node *thptr=hptr;
		while(thptr!=NULL)
		{   
		    if(thptr->next!=NULL)
			  printf("%dx^%d+",thptr->data,i);
			else
			  printf("%dx^%d",thptr->data,i);
			thptr=thptr->next;i++;
		}
		printf("\n");
	return;
}


struct node * add(struct node *a,struct node *b,struct node *c)
 {
   int z;
   struct node *thptr1=a;
   struct node *thptr2=b;
   struct node *thptr3=c;
  
   while(thptr1 != NULL || thptr2 != NULL)
   {
      struct node *temp= (struct node *)malloc(sizeof(struct node));
   
      if(thptr1 == NULL )
      {
	z=thptr2->data;
	c=ins(c,z);
	thptr2=thptr2->next;
      }
      else if(thptr2 == NULL )     
      {
        
	z=thptr1->data;
	c=ins(c,z);
	thptr1=thptr1->next;

      }
      else
     {
	z=thptr1->data+thptr2->data;
	c=ins(c,z);
	thptr1=thptr1->next;
	thptr2=thptr2->next;
     }


   }

 return(c);

 }


 
struct node *ins(struct node *p,int l)
{
	struct node *thptr=p;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		temp->data=l;
		p=temp;
		p->next=NULL;
	}
	else
	{
		temp->data=l;
		while(thptr->next!=NULL)
		thptr=thptr->next;
		thptr->next=temp;
		temp->next=NULL;
	}
	return(p);
}


struct node *reverse(struct node *a)
{
	struct node *prev,*cur,*nex;
	prev=NULL;
	cur=a;
	while(cur!=NULL)
	{
		nex=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nex;
	}
	a=prev;
	return(a);
}

struct node *mul(struct node *a,struct node *b,struct node *c,int p,int q)
{
	int i,j,d=0;
	struct node *thptr1=a;
	struct node *thptr2=b;
	struct node *thptr3=c;
	for(i=0;i<=q;i++)
	{
		d=0;
		thptr2=b;thptr1=a;
		for(j=0;j<q-i;j++)
		thptr2=thptr2->next;
		while(thptr2!=NULL && thptr1!=NULL)
		{
			d=d+(thptr2->data)*(thptr1->data);
			thptr2=thptr2->next;
			thptr1=thptr1->next;
		}
		c=ins(c,d);
	}
	d=0;
	for(i=0;i<p;i++)
	{
		d=0;
		thptr2=b;thptr1=a;
		for(j=0;j<=i;j++)
		thptr1=thptr1->next;
		while(thptr1!=NULL && thptr2!=NULL)
		{
			d=d+(thptr1->data)*(thptr2->data);
			thptr1=thptr1->next;
			thptr2=thptr2->next;
		}
		c=ins(c,d);
	}
	return(c);
}
































