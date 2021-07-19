#include<stdio.h>
main()
{
	int i,j,n,temp,a[25],x;
	printf("enter size of array");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		x=i;
		for(j=i+1;j<n;j++)
		{
			if(a[x]>a[j])
			{
				x=j;
			}
			if(x!=i)
			{
				temp=a[x];
				a[x]=a[i];
				a[i]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
