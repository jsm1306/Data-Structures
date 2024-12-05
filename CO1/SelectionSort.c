#include<stdio.h>
void accept(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void selectionsort(int a[],int n)
{
	int max,mindex,rindex=n-1,rounds=1,i;
	while(rounds<n)
	{
		max=a[0];
		for(i=0;i<=(n-rounds);i++)
		{
			if(a[i]>max)
			{
				max=a[i];
				mindex=i;
			}
		}
			a[mindex]=a[rindex];
			a[rindex]=max;
			rounds++;
		rindex--;
	}
}
int main()
{
	int i,n;
	printf("Enter array size: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements in the array: ");
	accept(a,n);
	printf("before sorting:\n");
	display(a,n);
	selectionsort(a,n);
	printf("after sorting:\n");
	display(a,n);
}
