#include<stdio.h>
void binarysearch(int low,int high,int a[],int x)
{
	if(low<=high)
	{
	    int	mid=(low+high)/2;
		if(x==a[mid])
		{
			printf("\t the pos of element is = %d",mid);
		}
		else if(x<a[mid])
		{
			return binarysearch(low,mid-1,a,x);
		}
	    else
		{
	        return binarysearch(mid+1,high,a,x);	
		}	
	}
}
main()
{
	int low,high,a[25],x,n,i;
	printf("\t enter size of array \t");
	scanf("%d",&n);
	printf("\t enter array elements \t");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\t enter element to search \t");
	scanf("%d",&x);
	low=1;
	high=n;
	binarysearch(1,n,a,x);
}
