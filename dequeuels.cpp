#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 
struct node
{
 	int data;
 	struct node*left,*right;
}*front=NULL,*rear=NULL;
void insertfront()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\t enter node data to insert \t");
	scanf("%d",&newnode->data);
	newnode->right=NULL;
	newnode->left=NULL;
	if(front==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		newnode->right=front;
		front->left=newnode;
		front=newnode;
	}
}
void insertrear()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\t enter node data to insert \t");
	scanf("%d",&newnode->data);
	newnode->right=NULL;
	newnode->left=NULL;
	if(rear==NULL)
	{
		rear=newnode;
		front=newnode;
	}
	else
	{
		newnode->left=rear;
		rear->right=newnode;
		rear=newnode;
	}
}
void delfront()
{
	if(front==NULL)
	{
		printf("\t double ended queue is empty \t");
	}
	else
	{
		struct node*p=front;
		printf("\t deleted element is = %d",p->data);
		front=p->right;
		if(front==NULL)
		{  
		    rear=NULL;
		}
		else
		{
			front->left=NULL;
		}
		free(p);
	}
}
void delrear()
{
	if(rear==NULL)
	{
		printf("\t double ended queue is empty \t");
	}
	else
	{
		struct node*p=rear;
		printf("\t deleted element is = %d",p->data);
		rear=p->left;
		if(rear==NULL)
		{
			front=NULL;
		}
		else
		{
			rear->right=NULL;
		}
		free(p);
	}
}
void display()
{
	if(front==NULL)
	{
		printf("\t double ended queue is empty \t");
	}
	else
	{
		printf("\t double ended queue elements are ==");
		struct node*p=front;
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
	printf("\t1.insertfront\t2.insertrear\t3.delfront\t4.delrear\t5.display\t6.exit\t");
	while(1)
	{
		printf("\n enter choice \t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insertfront();
			       break;
			case 2:insertrear();
			       break;
			case 3:delfront();
			       break;
			case 4:delrear();
			       break;
			case 5:display();
			       break;
			case 6:exit(0);
			default:printf("\t wrong choice \t");
		}
	}
}
