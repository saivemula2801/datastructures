#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

int queue[SIZE],front=-1,rear=-1;
void insert()
{
    int value;	
	if(rear==SIZE-1)
	{
		printf("\t queue is full \t");
	}
	else
	{
		printf("\t enter value to insert \n");
        scanf("%d",&value);
  		if(front==-1)
  		{
  			front=0;
		}
		rear=rear+1;
		queue[rear]=value;
    }
}
void del()
{
	if(front==-1)
	{
		printf("\t empty queue \t");
	}
	else
	{
		printf("deleted element is=%d",queue[front]);
		front=front+1;
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
		printf("queue is empty");
	}
	else
	{
	    printf("\t queue elements are \t");
		int i;
		for(i=front;i<=rear;i++)
		{
			printf("%d",queue[i]);
		}
	}
}
main()
{
	int choice;
	printf("\t1.insert\t2.delete\t3.display\t4.exit\t");
	while(1)
	{
		printf("\n enter choice \t");
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
