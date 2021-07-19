#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node*left,*right;
}*head=NULL;
int length()
{
	int count=0;
	struct node*p;
	p=head;
	while(p!=NULL)
    {
    	count++;
    	p=p->right;
	}	
	return count;
}
void insertbegin()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\t enter data to insert \t");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
	    struct node*p=head;	
        newnode->right=head;
		head->left=newnode;
		head=newnode;	    
	}
}
void insertend()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\t enter data to insert \t");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct node*p=head;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=newnode;
		newnode->left=p;
	}
}
void insertspecific()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	int loc,i=1;
	printf("\t enter location to insert after the specific loc \t");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("\t invalid location \t");
	}
	else
	{
		printf("\t enter value to insert \t");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
		struct node*p=head;
		while(i<loc)
		{
			p=p->right;
		}
		newnode->right=p->right;
		p->right->left=newnode;
		newnode->left=p;
		p->right=newnode;
	}
}
void deleteoper()
{
	int loc;
	printf("\t enter location");
	scanf("%d",&loc);
	if(loc>length())
	{ 
	    printf("invalid location");
	}
	else if(loc==1)
	{
		struct node*p=head;
		head=p->right;
		head->left=NULL;
		p->right=NULL;
		free(p);
	}
	else
	{
		int i=1;
		struct node*p=head;
		struct node*q;
		while(i<loc-1)
		{
			p=p->right;
		}
		q=p->right;
		p->right=q->right;
		q->right->left=p;
		free(q);
	}
}
void deleteend()
{
	struct node*p=head;
	struct node*q;
	while(p->right!=NULL)
	{
		q=p;
		p=p->right;
	}
	q->right=NULL;
	p->left=NULL;
	printf("last node deleted");
		free(p);
}
void display()
{
	struct node*p=head;
	if(head==NULL)
	{
		printf("empety linked list");
	}
	else
	{
		printf("\tlinked list elements is \t");
		while(p!=NULL)
		{
			printf("%d->",p->data);
			p=p->right;
		}
	}
}
main()
{
	int choice;
	printf("\t1.insert begin\t2.insert end\t3.insert specific\t4.delete\t5.delete end\t6.display\t7.exit\t");
	while(1)
	{
		printf("\n enter choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insertbegin();
			        break;
			case 2:insertend();
			        break;
			case 3:insertspecific();
			       break;
			case 4:deleteoper();
			       break;
			case 5:deleteend();
			       break;
			case 6:display();
			
			       break;
			case 7:exit(0);
			default:printf("wrong choice");
		}
		
	}
}
