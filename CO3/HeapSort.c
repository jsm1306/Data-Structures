#include<stdio.h>
void adjust(int a[], int i, int n)
{
	int key=a[i], j=2*i;
	while(j<=n)
	{
		if((j<n) && (a[j]<a[j+1]))
		j++;
		if(key>a[j])
    	break;
    	else 
    	{
    		a[j/2]=a[j];
      		j=j*2; 
		}
	}
	a[j/2]=key;
}
void heapify(int a[],int n) 
{
	int i;
  for( i=n/2;i>=1;i--) 
  	adjust(a,i,n);
}
void heapsort(int a[],int n) {
  heapify(a,n);
  int i=n-1;
  while(i>1) {
    int temp=a[1];
    a[1]=a[i];
    a[i]=temp;
    i--;
    adjust(a,1,i);
  }
}
int main() {
  int n,i;
  printf("Enter the size of the array: ");
  scanf("%i",&n);
  n=n+1;
  int a[n];
  a[0]=n;
  printf("Enter the elements: ");
  for(i=1;i<n;i++) 
  scanf("%i",&a[i]);
  printf("Elements before sorting: ");
  for(i=1;i<n;i++)
  printf("%i ",a[i]);
  printf("\n");
  heapsort(a,n);
  printf("Elements after sorting: ");
  for(i=1;i<n;i++)
  printf("%i ",a[i]);
}
