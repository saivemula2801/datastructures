#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int top=-1;
int stack[SIZE];
void push()
{
	int value;
	if(top==SIZE-1)
	{
		printf("\t stack is full \t");
	}
	else
	{
		printf("\t enter value to insert \t");
		scanf("%d",&value);
		top=top+1;
		stack[top]=value;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\t stack is empty \t");
	}
	else
	{
	    printf("popped element is =%d",stack[top]);	
	    top=top-1;
	}
}
void display()
{
	if(top==-1)
	{
		printf("\t stack is empty \t");
	}
	else
	{
		printf("\t stack elements are \t");
		while(top>=0)
		{
			printf("%d",stack[top]);
			top--;
		}
	}
}
main()
{
	int choice;
	printf("\t1.push\t2.pop\t3.display\t4.exit\t");
	while(1)
	{
		printf("\n enter choice \n");
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
