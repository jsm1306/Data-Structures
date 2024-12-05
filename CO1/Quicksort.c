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
int partition(int a[],int low,int high)
{
	int i=low+1,temp;//descending order:i=1
	int j=high;
	int p=a[low];
	while(i<j)
	{
		while(a[i]<p)//descending order a[i]>p
		i++;
		while(a[j]>p)//descending order a[j]<p
		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	if(j<i)
	{
		a[low]=a[j];
		a[j]=p;
	}
	return j;
}
void quicksort(int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quicksort(a,low,j-1);
		quicksort(a,j+1,high);
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
	quicksort(a,0,n-1);
	display(a,n);
}
