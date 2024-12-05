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
void insertionsort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{ key=a[i];
	j=i-1;
	while(j>=0 && key<a[j])//descending order key>a[j]
	{
		a[j+1]=a[j];
		j--;
	} a[j+1]=key;
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
	insertionsort(a,n);
	display(a,n);
}
