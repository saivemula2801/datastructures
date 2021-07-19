#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int cqueue[SIZE],front=-1,rear=-1;
void insert()
{
	if(front==0 && rear==SIZE-1||front==rear+1)
	{
		printf("\t cqueue is full");
	}
	else
	{
		int value;
		printf("\t enter value to insert\t");
		scanf("%d",&value);
		if(rear==SIZE-1 && front!=0)
		{
			rear=-1;
		}
   	    rear=rear+1;
		cqueue[rear]=value;
	 	if(front==-1)
    	{
		 	front=0;
		}	
	}
}
void del()
{
	if(front==-1 && rear==-1)
	{
		printf("\t cqueue is empty \t");
	}
	else
	{
		printf("deleted element is =%d",cqueue[front]);
		front=front+1;
		if(front==SIZE)
		{
			front=0;
		}
		if(front==rear+1)
		{
			front=-1;
			rear=-1;
		}
	}
}
void display()
{
	if(front==-1)
	{
		printf("\t queue is empty");
	}
	else
	{
		if(front<=rear)
		{
			while(front<=rear)
			{
				printf("%d",cqueue[front]);
				front=front+1;
			}
		}
		else
		{
			printf("\t cqueue elements are \t");
			while(front<=SIZE-1)
			{
				printf("%d",cqueue[front]);
				front=front+1;
			}
			front=0;
			while(front<=rear)
			{
				printf("%d",cqueue[front]);
				front=front+1;
			}
		}
	}
}
main()
{
	int choice;
	printf("\t1.insert\t2.delete\t3.display\t4.exit\t");
	while(1)
	{
		printf("\t enter choice \t");
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
			default:printf("wrong choice");	
		}
	}
}
