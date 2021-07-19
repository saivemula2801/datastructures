#include<stdio.h>
main()
{
	int n,ele,a[20],i;
	printf("\t enter size of array \t");
	scanf("%d",&n);
	printf("\n enter array elements \t ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n enter element to search \t ");
	scanf("%d",&ele);
	for(i=1;i<=n;i++)
	{
		if(ele==a[i])
		{
			printf("\t the position of element is = %d",i);
		}
	}

}
