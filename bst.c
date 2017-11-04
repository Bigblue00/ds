
#include<stdio.h>
#include<stdlib.h>
 struct node *newNode(int item);
 struct node* insert(struct node* node, int key);
struct node * minValueNode(struct node* node);
struct node* deleteNode(struct node* root, int key);
void inorder(struct node *root);  
struct node
{
    int key;
    struct node *left, *right;
};
 
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
 
struct node* insert(struct node* node, int key)
{

    if (node == NULL)
	    return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
struct node* deleteNode(struct node* root, int key)
{
  
    if (root == NULL) return root;
 

    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else
    {
       
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minValueNode(root->right);
 
        root->key = temp->key;
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{
  int ch,key,y,n,node;
       while(1)
	
	{
		printf("\n1.Insert\n2.Delete\n3.In-order\n4.treesort\n5.ekeyit\n");
                printf("enter your choice");
                scanf("%d",&ch);
                struct node *node1=NULL;
                switch(ch)
		{
                 case 1:  printf("enter the num to be inserted");
                          scanf("%d",&key);
                          node=insert(node,key);
                          break;
                case 2:   printf("enter the num to be deleted");
                          scanf("%d",&y);
                          node=insert(node,y);
                          break;
                case 3:   printf("the inoder is ");
                          inorder(node);
                          break;
                   
                case 4:  ekeyit(0);
                          break;         
                
                default: printf("invalid num");
                         break;
                }
		
	}
	return(0);
}
