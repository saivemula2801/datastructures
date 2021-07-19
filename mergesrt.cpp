#include<stdio.h>
void merge(int a[],int lb,int mid,int ub)
{
	int i,j,k;
	int b[20];
	i=lb;
	j=mid+1;
	k=lb;
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			k++;
			i++;
		}
		else
		{
			b[k]=a[j];
			k++;
			j++;
		}
		
	}
	while(j<=ub)
		{
			b[k]=a[j];
			k++;
			j++;
		}
		while(i<=mid)
		{
			b[k]=a[i];
			k++;
			i++;
		}
	
	for(i=lb;i<=ub;i++)
	{
		a[i]=b[i];
	}
}
void mergesort(int a[],int lb,int ub)
{
	int mid;
	if (lb<ub)
	{
		mid=(lb+ub)/2;
		mergesort(a,lb,mid);
		mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
main()
{
	int n,i,a[25];
	printf("enter size of array");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}

