#include<stdio.h>
int i;
void accept(int a[],int n)
{
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void display(int a[],int n)
{
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int partition(int a[], int low, int high)
{
	int pivot=a[low],i=low+1,j=high,temp;
	while(i<j)
	{
		while(a[i]<pivot)
		i++;
		while(a[j]>pivot)
		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	if(i>j)
	{
		a[low]=a[j];
		a[j]=pivot;
	}
	return j;
}
void quicksort(int a[],int low, int high)
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
	scanf("%d",&n);
	int a[n];
	accept(a,n);
	display(a,n);
	quicksort(a,0,n-1);
	printf("\n");
	display(a,n);
}
