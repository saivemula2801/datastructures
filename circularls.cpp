#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
}*head=NULL;
int length()
{
	struct node*p=head;
	int count=0;
	while(p->link!=head)
	{
	    count++;
		p=p->link;	
	}
	return count+1;
}
void insertend()
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\t enter data to insert \t");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;
		head->link=head;
	}
	else
	{
		struct node*p=head;
		while(p->link!=head)
		{
			p=p->link;
		}
		p->link=newnode;
		newnode->link=head;
	}
}
void insertspecific()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	int loc,i=1;
	printf("\t enter node data after this loc \t");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("\t invalid location \t");
	}
	else
	{
		struct node*p=head;
		while(i<loc)
		{
		    p=p->link;
            i++;		 
		}
		printf("\t enter node data \t");
		scanf("%d",&newnode->data);
		newnode->link=NULL;
		newnode->link=p->link;
		p->link=newnode;
	}
}
void deletebegin()
{
	if(head==NULL)
	{
		printf("\t empty linked list \t ");
	}
	else if(head->link==head)
	{
		head=NULL;
		free(head);
	}
	else
	{
		struct node*p=head;
		while(p->link!=head)
		{
			p=p->link;
		}
		p->link=head->link;
		free(head);
		head=p->link;
	}
	printf("\t node deleted \t");
}
void deleteend()
{
	if(head==NULL)
	{
		printf("\t empty linked list \t");
	}
	else if(head->link==head)
	{
		head=NULL;
		free(head);
	}
	else
	{
		struct node*p=head,*q;
		while(p->link!=head)
		{
			q=p;
			p=p->link;
		}
	    q->link=p->link;
		free(p);
	}
	printf("\t node deleted \t");
}
void deletespecific()
{
	int loc,i=1;
	printf("enter location to delete");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("\t invalid location \t");
	}
	else
	{
		struct node*p=head,*q;
     	while(i<loc-1)
    	{
	    	p=p->link;
		    i++;
    	}	
	    q=p->link;
	    p->link=q->link;
    	free(q);
    }
}

main()
{
	int choice;
	printf("\t1.insertbegin\t2.insertend\t3.insertspecific\t4.deletebegin\t5.deleteend\t6.deletespecific\t7.display\t8.exit\t");
	while(1)
	{
		printf("\n enter choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insertbegin();
			       break;
			case 2:insertend();
			       break;
			case 3:insertspecific();
			       break;
			case 4:deletebegin();
			       break;
			case 5:deleteend();
			       break;
			case 6:deletespecific();
			       break;
			case 7:display();
			        break;
			case 8:exit(0);
			default:printf("wrong choice");
		}
	}
}
