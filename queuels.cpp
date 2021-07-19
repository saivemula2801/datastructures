#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
 
struct node
{
	int data;
	struct node*link;
}*front=NULL,*rear=NULL;
void insert()
{

	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\t enter node data to insert \t");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(front==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->link=newnode;
		rear=newnode;
	}
}
void del() 	
{
	if(front==NULL)
	{
		printf("\t queue linked list is empty \t");
	}
	else
	{
		struct node*p=front;
		printf("\t deleted element is = %d",p->data);
        front=p->link;
		free(p); 
	}
}
void display()
{
	printf("\t queue linked list elements are \t");
	if(front==NULL)
	{
		printf("\t queue linked list is empty \t");
	}
	else
	{
		struct node*p=front;
		while(p!=NULL)
		{
			printf("%d->",p->data);
			p=p->link;
		}1
		1
		1
	}
}
main()
{
	int choice;
	printf("\t1.insert\t2.delete\t3.display\t4.exit\t");
	while(1)
	{
		printf("\n enter choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
			       break;
			case 2:del();
			       break;
			case 3:display();
			       break;
			case 4:exit(0);
			default:printf("\t wrong choice \t");
		}
	}
}
