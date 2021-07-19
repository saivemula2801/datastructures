#include<stdio.h>
main()
{
	int mid,low,high,n,ele,i,a[20];
	printf("\t enter size of array \t ");
	scanf("%d",&n);
	printf("\t enter array elements \t");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\t enter element to search \t");
	scanf("%d",&ele);
	low=1;
	high=n;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ele==a[mid])
		{
			printf("\t the position of element is = %d",mid);
			break;
		}
		else if(ele<a[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
}
