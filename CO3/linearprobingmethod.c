#include<stdio.h>
#include<stdlib.h>
#define s 5
int a[s]={NULL};
void insert()
{
	int i,j,k,val;
	printf("Enter value:");
	scanf("%d",&val);
	k=val%s;
	for(i=0;i<s;i++)
	{
		j=(k+i)%s;
		if(a[j]==NULL)
		{
			a[j]=val;
			break;
		}
		if(i==s-1)
	printf("Full");
	}
	
}
void display()
{
	int i;
	for(i=0;i<s;i++)
	{
		printf("%d \n",a[i]);
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("1.Insert\n2.Display\n3.Exit\nSelect an option:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				exit(0);
			default:
				printf("Enter valid option");
				break;
		}
	}
}
