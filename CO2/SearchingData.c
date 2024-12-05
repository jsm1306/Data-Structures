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
void search()
{
	int n,f=0;
	char s[20];
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		printf("Enter employee name you want to search:\n");
		scanf(" %s",&s);
		node=head;
		while(node!=NULL)
		{
			if(strcmp(s,node->name)==0)
			{
				f=1;
				break;
			} node=node->next;
		}
		if(f==1)
		{
			printf("Employee found and details are:\n");
			printf(" %s\t %s\t %d\t %d\t %.2f\n",node->name,node->desig,node->id,node->deptno,node->sal);
		}
		else
		{
			printf("Employee not found\n");
		}
	}
}
int main()
{
  create();
  printf("Data is:\n");
  display();
  search();
}
