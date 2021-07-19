#include<stdio.h>
#include<stdlib.h>
int q[20],stack[20],top=-1,rear=-1,front=-1,vis[20],a[10][10];
void add(int x)
{
	if(rear==19)
	{
		printf("\t queue is full \t");
	}
	else if(rear==-1 && front==-1)
	{
		rear=0;
		front=0;
		q[rear]=x;
		rear=rear+1;
	}
	else
	{
		q[rear]=x;
		rear=rear+1;
	}
}
int del()
{
	int k;
	if((front>rear)||(front==-1))
	{
		return 0;
	}
	else
	{
		k=q[front++];
		return k;
	}
}
void bfs(int s,int n)
{
	int p,i;
	add(s);
	vis[s]=1;
	p=del();
	if(p!=0)
	{
		printf("%d",p);
	}
	while(p!=0)
	{
		for(i=1;i<=n;i++)
		{
			if(a[p][i]!=0 && vis[i]==0)
			{
				add(i);
				vis[i]=1;
			}
			p=del();
			if(p!=0)
			{
				printf("%d",p);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			bfs(i,n);
		}
   }
}
void push(int x)
{
	if(top==19)
	{
		printf("\t stack is full \t");
	}
	else
	{
		stack[top++]=x;
	}
}
int pop()
{
	int k;
	if(top==-1)
	{
		return 0;
	}
	else 
	{
		k=stack[top--];
		return k;
	}
}
void dfs(int s,int n)
{
	int i,k;
	push(s);
	vis[s]=1;
	k=pop();
	if(k!=0)
	{
		printf("%d",k);
	}
	while(k!=0)
	{
		for(i=1;i<=n;i++)
		{
			if(a[k][i]!=0 && vis[i==0])
			{
				push(i);
				vis[i]=1;
			}
			k=pop();
			if(k!=0)
			{
				printf("%d",k);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i,n);
		}
	}
}
main()
{
	int n,i,s,choice,j;
	printf("\t enter number of vertices \t");
	scanf("%d",&n);
	printf("\t enter adjacency matrix \t");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	while(1)
	{
	   printf("\t1.bfs \t2.dfs \t3.3xit \t");
	   printf("\t enter choice \t");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	   	case 1:bfs(s,n);
	   	       break;
	   	case 2:dfs(s,n);
	   	        break;
	   	case 3:exit(0);
	   	default:printf("\t wrong choice \t");
	   }
	}
}
