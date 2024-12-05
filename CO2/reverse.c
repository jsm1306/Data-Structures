#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee{
	int id, deptno;
	char desig[20],name[20];
	float sal;
	struct employee *next;
} *head,*node, *newnode,*NP1,*NP2,*temp;
void create()
{
	int count,i;
	printf("Enter number of employees:\n");
	scanf("%d",&count);
	for(i=1;i<=count;i++)
	{
		newnode=(struct employee*)malloc(sizeof(struct employee));
		printf("Enter name,desig,id,deptno,salaray:\n");
		scanf(" %s %s %d %d %f",&newnode->name,&newnode->desig,&newnode->id,&newnode->deptno,&newnode->sal);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			node=head;
			while(node->next!=NULL)
			{
				node=node->next;
			}node->next=newnode;
		} 
	}
}
void display()
{
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		node=head;
		while(node!=NULL)
		{
			printf(" %s\t %s\t %d\t %d\t %.2f\n",node->name,node->desig,node->id,node->deptno,node->sal);
			node=node->next;
		}
	}
}
void reverse()
{
	NP1=head;
	NP2=NULL;
	temp=NULL;
	while(NP1!=NULL)
	{
		NP2=NP1;
		NP1=NP1->next;
		NP2->next=temp;
		temp=NP2;
	}
	head=NP2;
}
int main()
{
  create();
  printf("Data before reversing \n");
  display();
  reverse();
  printf("Data after reversing \n");
  display();
}
