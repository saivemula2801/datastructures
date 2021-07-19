#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *link;
}*head=NULL;
int length()
{
	int count=0;
	struct node*p=head;
	while(p!=NULL)
	{
		count++;
		p=p->link;
	}
	return count;
}
void insertbegin()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter value \t");
	scanf("%d",&newnode->value);
	newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->link=head;
		head=newnode;
	}
}
void insertend()
{
    struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf(" \nenter the value \t");
    scanf("%d",&newnode->value);
	newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;
	}	
	else
	{
	    struct node*p=head;
		while(p->link!=NULL)
		{
			p=p->link;
		}	
		p->link=newnode;
	}
}
void insertmiddle()
{
	int loc,len,i=1;
	 struct node*newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the location to insert after\t");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	{
		printf("invalid location");
	}
	
	else
	{
		p=head;

		while(i<loc)
		{
			p=p->link;
			i++;
		}
		printf("\nenter the value \t");
		scanf("%d",&newnode->value);
		newnode->link=NULL;
		newnode->link=p->link;
		p->link=newnode;
	}
}
void del()
{
	int  loc;
	struct node*temp;
	printf("\nenter location to delete \t");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("\n invalid location \n");
	}
	else if(loc==1)
	{
		temp=head;
		head=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		struct node*p=head;
		struct node*q;
		int i=1;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}
void traverse()
{
	struct node*p;
	p=head;
	if(p==NULL)
	{
		printf("\tempty linked list\t");
	}
	else
	{
	    printf("\n linked list elements is \t");
		while(p!=NULL)
		{
			printf("%d->",p->value);
			p=p->link;
		}
	}
}
main()
{
	int choice;
	printf("\n1.insertbegin\t2.insertend\t3.insertmiddle\t4.delete\t5.display\t6.exit\t");
	while(1)
	{
		printf("\nenter choice \t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insertbegin();
			       break;
			case 2:insertend();
			        break;
			case 3:insertmiddle();
			       break;
  			case 4:del();
			       break;
			case 5:traverse();
			       break;
			case 6:exit(0);
			default:printf("invalid choice");
		}
	
	}
}
