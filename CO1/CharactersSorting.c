#include <stdio.h>
void accept(char a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf(" %c",&a[i]);
	}
}
void display(char a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c ",a[i]);
	}
}
void selectionSort(char arr[], int n) {
    int i, j, mi;
    char temp;
    for(i=0;i<n-1;i++) 
	{
        mi=i;
        for(j = i+1; j < n; j++) {
            if (arr[j] < arr[mi]) {
                mi = j;
            }
        }
        temp = arr[mi];
        arr[mi] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    char a[n];
    printf("Enter %d characters: ", n);
    accept(a,n);
    printf("Original array: ");
    display(a,n);
    selectionSort(a, n);
    printf("\nSorted array in ascending order: ");
    display(a,n);
}
