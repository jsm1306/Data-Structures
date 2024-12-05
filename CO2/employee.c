#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
	int id, deptno;
	char name[20],desig[20];
	float salary;
	struct employee *next;
}*head,*node,*newnode,*np1,*np2;
void create()
{
	int i,c;
	printf("Enter number of movies to be added");
	scanf("%d",&c);
	for(i=1;i<=count;i++)
	{
		newnode=(struct movie*)malloc(sizeof(struct movie));
		printf("Enter Movie Details:\n");
		scanf(" %s %s %s %s %d %f",&newnode->mname,&newnode->ml,&newnode->fl,&newnode->dir,&newnode->yor,&newnode->rating);
		newnode->next=NULL;
		if(head!=NULL)
		{
			node=head;
			while(node->next!=NULL)
			{
				node=node->next;
			}node->next=newnode;
		}
		else
		head=newnode;
	}
}
