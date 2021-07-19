#include<stdio.h>
main()
{
	int a[30],n,i,j,temp;
	printf("enter size of array");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
		    a[j+1]=a[j];
		    j--;
		}
		a[j+1]=temp;
	}
	printf("insertion sorted elements are");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
