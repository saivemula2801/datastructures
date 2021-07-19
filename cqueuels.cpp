#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
}*front=NULL,*rear=NULL;
void insert()
{
	int data;
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\t enter node data to insert \t");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(front==NULL)
	{
		front=newnode;
		rear=newnode;
		rear->link=newnode;
	}
	else
	{
		rear->link=newnode;
		newnode->link=front;
		rear=newnode;
	}
}
void del()
{
	if(front==NULL)
	{
		printf("\t cqueue linked list is empty \t");
    }
    else if(front==rear)
    {
        printf("\t deleted element is = %d",front->data); 	
    	front=NULL;
    	rear=NULL;
	}
	else
	{
		struct node*p=front;
		printf("\t deleted element is = %d",p->data);
		front=p->link;
		rear->link=front;
		free(p);
	}
}
void display()
{
	if(front==NULL)
	{
		printf("\t cqueue linked list is empty \t");
	}
	else
	{
		struct node*p=front;
		while(p->link!=front)
		{
			printf("%d->",p->data);
			p=p->link;
	    }
	    printf("%d",p->data);
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
