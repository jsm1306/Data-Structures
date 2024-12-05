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
void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;
	int c[30];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])//descending order a[i]>a[j]
		{
			c[k++]=a[i++];
		}
		else
		{
			c[k++]=a[j++];
		}
	}//for pushing leftover elements to temporary array
	while(i<=mid)
	{
		c[k++]=a[i++];
	}
	while(j<=high)
	{
		c[k++]=a[j++];
	}//for copying temporary array elements into original array
	for(k=low;k<=high;k++)
	{
		a[k]=c[k];
	}
}
void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int n;
	printf("Enter size: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:");
	accept(a,n);
	mergesort(a,0,n-1);
	display(a,n);
	
}

