#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct node *lcptr;
 int data;
 int height;
 struct node *rcptr;
};

struct node *insert(struct node *,int );
void inorder(struct node *);
void heightupdate(struct node *);
void postorder(struct node *);
int heighttree(struct node *);
struct node *rotateleft(struct node *);
struct node *rotateright(struct node *);
struct node *rotateleftright(struct node *);
struct node *rotaterightleft(struct node *);
struct node *del(struct node *,int );
int bf(struct node *);

int main()
{
  int option,x;
  struct node *rptr=NULL;
  do
     {
           printf("\n1.insert\n2.inorder display\n3.postorder display\n4.delete\n.5EXIT\n");
           scanf("%d",&option);
           if(option==1)
           {
             printf("enter the num to be inserted ");
             scanf("%d",&x);
             rptr=insert(rptr,x);
 
           }
           else if(option==2)
           inorder(rptr);
           
           else if(option==3)
           postorder(rptr);
           
           else if(option==4)
           {
             printf("enter the num to be deleted ");
             scanf("%d",&x);
             rptr=del(rptr,x);
           }

 
     }while(option!=5);
 


 return(0);
}

struct node *insert(struct node *ptr,int x )
{
  int h1,h2;
            if(ptr==NULL)
             {
                  ptr=(struct node *)malloc(sizeof(struct node));
                  ptr->data=x;
                  ptr->height=0;
                  ptr->lcptr=NULL;
                  ptr->rcptr=NULL;

             }

            else
            {

                     if(x<ptr->data)
                     {
                       ptr->lcptr=insert(ptr->lcptr,x);
                       if(bf(ptr)==2 || bf(ptr==-2))
                         { 
                            if(x<(ptr->lcptr)->data)
                            ptr=rotateright(ptr);
                           
                            else
                            ptr=rotateleftright(ptr);

                         }

                     }
                     
                     else
                     {
                         ptr->rcptr=insert(ptr->rcptr,x);
                         if(bf(ptr)==2 || bf(ptr==-2))
                         { 
                            if(x<(ptr->rcptr)->data)
                            ptr=rotaterightleft(ptr);
                           
                            else
                            ptr=rotateleft(ptr);
                          }


                     }

                    heightupdate(ptr);

            }
   
  return(ptr);


}

void inorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    inorder(ptr->lcptr);
    printf("%d  ",ptr->data);
    inorder(ptr->rcptr);

  }


}

void postorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    postorder(ptr->lcptr);
    postorder(ptr->rcptr);
    printf("%d  ",ptr->data);
    

  }


}


void heightupdate(struct node *ptr)
{
  int h1=heighttree(ptr->lcptr),h2=heighttree(ptr->rcptr);
  if(h1<h2)
  ptr->height=h2+1;
  else
  ptr->height=h1+1;

}

int heighttree(struct node *ptr)
{
 if(ptr!=NULL)
 return(ptr->height);
 else
 return(-1);

}

int bf(struct node *ptr)
{
 if(ptr==NULL)
 return(0);
 else
 return(heighttree(ptr->lcptr)-heighttree(ptr->rcptr));


}

struct node *rotateright(struct node *ptr)
{
  struct node *jptr=ptr;
  struct node *kptr=jptr->lcptr;
  jptr->lcptr=kptr->rcptr;
  kptr->rcptr=jptr;
  heightupdate(jptr);
  heightupdate(kptr);
  return(kptr);

}

struct node *rotateleft(struct node *ptr)
{
  struct node *jptr=ptr;
  struct node *kptr=jptr->rcptr;
  jptr->rcptr=kptr->lcptr;
  kptr->lcptr=jptr;
  heightupdate(jptr);
  heightupdate(kptr);
  return(kptr);

}


struct node *rotateleftright(struct node *ptr)
{
  struct node *jptr=ptr;
  struct node *kptr=jptr->lcptr;
  jptr->lcptr=rotateleft(kptr);
  return(rotateright(jptr));

}


struct node *rotaterightleft(struct node *ptr)
{
  struct node *jptr=ptr;
  struct node *kptr=jptr->rcptr;
  jptr->lcptr=rotateright(kptr);
  return(rotateleft(jptr));

}

struct node *del(struct node *ptr,int x)
{
  int z;
  if(ptr==NULL)
  return(ptr);
  if(x<ptr->data)
  ptr->lcptr=del(ptr->lcptr,x);
  else if(x>ptr->data)
  ptr->rcptr=del(ptr->rcptr,x);
  else
         {
           if(ptr->lcptr==NULL || ptr->rcptr==NULL)
               { 
                 struct node *temp;
                 if(ptr->lcptr!=NULL)
                 temp=ptr->lcptr;
                 else
                 temp=ptr->rcptr;
                   if(temp==NULL)
                   ptr=NULL;
                    else
                   *ptr=*temp;

               }
            else
               { 
                  struct node *tptr;
                  tptr=ptr->rcptr;
                  while(tptr->lcptr!=NULL)
                  tptr=tptr->lcptr;
                  ptr->data=tptr->data;
                  ptr->rcptr=del(ptr->rcptr,tptr->data);
                
               }

         }

if(ptr==NULL)
return(ptr);
heightupdate(ptr);
z=bf(ptr);
if(z==2 && bf(ptr->lcptr)>=0)
	ptr=rotateright(ptr);
	else if(z==2 && bf(ptr->lcptr)<0)
	ptr=rotateleftright(ptr);
	else if(z==-2 && bf(ptr->rcptr)<=0)
	ptr=rotateleft(ptr);
	else if(z==-2 && bf(ptr->rcptr)>0)
	ptr=rotaterightleft(ptr);
	return(ptr);


}





























