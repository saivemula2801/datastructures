#include<stdio.h>
void swap(int*a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void shellsort(int a[],int n)
{
	int i,j,gap;
	for(gap=n/2;gap>=1;gap=gap/2)
	{
		for(j=gap;j<n;j++)
		{
			for(i=j-gap;i>=0;i=i-gap)
			{
				if(a[i+gap]>a[i])
				     break;
				else
				     swap(&a[i+gap],&a[i]);
			}
		}
	}
}
main()
{
	int i,n,a[25];
	printf("enter size of array");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	shellsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
