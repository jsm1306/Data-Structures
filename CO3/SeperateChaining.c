#include<stdio.h>
#include<stdlib.h>
int i,k;
struct node{
	int x;
	struct node *next;
} *node, *newnode;
void insert(struct node *a[],int val, int n)
{
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->x=val;
	newnode->next=NULL;
	k=val%n;
	if(a[k]==NULL)
	{
		a[k]=newnode;
	}
	else
	{
		node=a[k];
		while(node->next!=NULL)
		{
			node=node->next;
		}
		node->next=newnode;
	}
}
void display(struct node *a[],int n)
{
	for(i=0;i<n;i++)
	{
		node=a[i];
		printf("%d ",i);
		while(node)
		{
			printf("%d ",node->x);
			node=node->next;
		}printf("\n");
	}
}
int main()
{
	int n,val;
	printf("Enter size:");
	scanf("%d",&n);
	struct node * a[n];
	for(i=0;i<n;i++)
	a[i]=NULL;
	for(i=0;i<n;i++)
	{
		printf("Enter value:");
		scanf("%d",&val);
		insert(a,val,n);
	}display(a,n);
}
