#include<stdio.h>
void quicksort(int a[],int lb,int ub)
{
	int pivot,i,j,temp;
	if(lb<ub)
	{
	pivot=lb;
	i=lb;
	j=ub;
	while(i<j)
	{
		while(a[i]<=a[pivot])
		{
			i++;
		}
		while(a[j]>a[pivot])
		{
			j--;
		}
		if(i<j)
		{
		    temp=a[i];
		    a[i]=a[j];
		    a[j]=temp;
	    }
    }
	temp=a[pivot];
	a[pivot]=a[j];
	a[j]=temp;
    quicksort(a,lb,j-1);
    quicksort(a,j+1,ub);
}
}

main()
{
	int n,a[25],i;
	printf("enter size of array");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
