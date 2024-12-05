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
void shellsort(int a[],int n)
{
	int i,j,gap,t;
	for(gap=n/2;gap>=1;gap/=2)
	{
		for(i=0;i<n-gap;i+=gap)
		{
			for(j=i+gap;j<n;j+=gap)
			{
				if(a[i]>a[j])//descending order:a[i]<a[j]
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
	}
}
int main()
{
	int n;
	printf("Enter the array size:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements:\n");
	accept(a,n);
	shellsort(a,n);
	printf("Elements after sorting:\n");
	display(a,n);
	
}
