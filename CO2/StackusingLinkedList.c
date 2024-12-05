#include<stdio.h>
#include<stdlib.h>//addbegin,delbegin
void create();
void display();
void push();
void pop();
void peep();
void peek();
struct employee{
	int id; 
	char name[20];
	float salary;
	struct employee *next;
}*head,*newnode, *node, *delnode;
int main()
{
	int opt;char choice;
	printf("Stack is being created:\n");
	create();
	printf("Stack is created\nThe data in stack is:\n");
	display();
	do
	{
		printf("1.Push\n2.Pop\n3.Peek\n4.Peep\n5.Display\nEnter Your Option:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				peep();
				break;
			case 5:
				display();
				break;
			default:
				printf("Invalid option");
				break;	
		}
		printf("Enter 'Y' to continue:\t");
		scanf("%s",&choice);
	}while(choice=='Y');
}
void create()
{
	int i, c;
	printf("Enter number of nodes to be created:\n");
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	{
		newnode=(struct employee*)malloc(sizeof(struct employee));
		printf("Enter employee id, name, salary:\n");
		scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
		if(head==NULL)
		{
			head=newnode;
			newnode->next=NULL;
		}
		else
		{
			newnode->next=head;
			head=newnode;
		}
	}
}
void display()
{
	if(head==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		node=head;
		while(node!=NULL)
		{
			printf("%d\t%s\t%.2f\n",node->id,node->name,node->salary);
			node=node->next;
		}
	}
}
void push()
{
	newnode=(struct employee*)malloc(sizeof(struct employee));
		printf("Enter employee id, name, salary:\n");
		scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
		if(head==NULL)
		{
			head=newnode;
			newnode->next=NULL;
		}
		else
		{
			newnode->next=head;
			head=newnode;
		}
}
void pop()
{
	if(head==NULL)
		printf("Stack is empty");
	else
	{
		delnode=head;
		head=delnode->next;
		printf("Data of deleted node is:\n");
		printf("%d\t%s\t%f",delnode->id,delnode->name,delnode->salary);
		free(delnode);
		delnode=NULL;
	}
}
void peek()
{
	if(head==NULL)
	printf("Stack is empty");
	else
	{
		printf("Top Element Data is:\n");
		printf("%d\t%s\t%f",head->id,head->name,head->salary);
	}
}
void peep()
{
	int id,found=0;
	if(head==NULL)
	printf("Stack is empty");
	else
	{
		printf("Enter Employee ID to search");
		scanf("%d",&id);
		node=head;
		while(node!=NULL)
		{
			if(node->id==id)
			{
				printf("%d\t%s\t%f",node->id,node->name,node->salary);
				found=1;
				break;
			}node=node->next;
		}
		if(found==0)
		printf("Data not found");
	}
}
