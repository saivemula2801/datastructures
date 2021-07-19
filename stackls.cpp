#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
}*top=NULL;
void push()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\t enter node data \t");
	scanf("%d",&newnode->data);
	if(top==NULL)
	{
		newnode->link=NULL;
		top=newnode;
	}
	else
	{
		newnode->link=top;
		top=newnode;
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("\t list is empty \t");
	}
	else
	{
		struct node*p=top;
		printf("deleted element is=%d",p->data);
		top=p->link;
	}
}
void display()
{
	if(top==NULL)
	{
		printf("\t list is empty \t");
	}
	else
	{
		struct node*p=top;
		printf("stack linked list elements are");
		while(p!=NULL)
		{
			printf("%d->",p->data);
			p=p->link;
		}
	}
}
main()
{
	int choice;
	printf("\t1.push\t2.pop\t3.display\t4.exit\n");
	while(1)
	{
		printf("\n enter choice \t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:exit(0);
			default:printf("wrong choice");
		}
	}
}
