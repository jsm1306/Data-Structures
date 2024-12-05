#include<stdio.h>
#include<stdlib.h>
struct employee{
	int id;
	char name[20];
	float salary;
	struct employee *next, *prev;
} *head, *newnode, *node, *delnode;
void create()
{
	int i, count;
	printf("Enter number of employees\n:");
	scanf("%d",&count);
	for(i=1;i<=count;i++)
	{
		newnode = (struct employee*)malloc(sizeof(struct employee));
		
		printf("Enter employee id, name, salary:\n");
		scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
		if(head==NULL)
		{
			head=newnode;
			newnode->prev=NULL;
		}
		else
		{
			node=head;
			while(node->next!=NULL)
			{
				node=node->next;
			}
			node->next=newnode;
			newnode->prev= node;
		}
		newnode->next=NULL;
	}
}
void display()
{
	if(head==NULL)
	{
		printf("List is empty\n");
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
void display1()
{
	node=head;
	while(node->next!=NULL)
	{
		node=node->next;
	}//node goes from 1st node to last node
	while(node!=NULL)
	{
		printf("%d\t%s\t%.2f\n",node->id,node->name,node->salary);
			node=node->prev;
	}
}
void addbegin()
{
	newnode = (struct employee*)malloc(sizeof(struct employee));		
	printf("Enter employee id, name, salary:\n");
	scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
	if(head!=NULL){
		newnode->next=head;
		head->prev=newnode;
		newnode->prev=NULL;
		head=newnode;
	}
	else
	{
		head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
}
void addend()
{
	newnode = (struct employee*)malloc(sizeof(struct employee));		
	printf("Enter employee id, name, salary:\n");
	scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
	if(head!=NULL)
	{
		node=head;
		while(node->next!=NULL)
		{
			node=node->next;
		}
		newnode->prev=node;
		node->next=newnode;
		newnode->next=NULL;
	}
	else
	{
		head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
}
void addatpos()
{
	int i,pos;
	newnode = (struct employee*)malloc(sizeof(struct employee));		
	printf("Enter employee id, name, salary:\n");
	scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
	printf("Enter Position number:\n");
	scanf("%d",&pos);
	node=head;
	for(i=1;i<pos-1;i++)
	{
		node=node->next;
	}
	newnode->next=node->next;
	node->next->prev=newnode;
	node->next=newnode;
	newnode->prev=node;
	if(pos==1)
	{
		newnode->prev=NULL;
		newnode->next=node;
		head=newnode;
	}
}
void delbegin()
{
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		delnode=head;
		head=head->next;
		printf("Data of deleted node is:\n");
		printf("%d\t%s\t%f",delnode->id,delnode->name,delnode->salary);
		free(delnode);
		delnode=NULL;
		head->prev=NULL;
	}
}
void delend()
{
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		node=head;
		while(node->next->next!=NULL)
		{
			node=node->next;
		}
		delnode=node->next;
		printf("Data of deleted node is:\n");
		printf("%d\t%s\t%f",delnode->id,delnode->name,delnode->salary);
		free(delnode);
		delnode=NULL;
		node->next=NULL;
	}
}
void delatpos()
{
	int i,pos;
	printf("Enter Position number:\n");
	scanf("%d",&pos);
	node=head;
	for(i=1;i<pos-1;i++)
	{
		node=node->next;
	}
	delnode=node->next;	
	printf("Data of deleted node is:\n");
	printf("%d\t%s\t%f",delnode->id,delnode->name,delnode->salary);
	delnode->next->prev=node->next;
	node->next=delnode->next;
	free(delnode);
	delnode=NULL;
}
int main()
{	int op;char choice;
	printf("Double linked list is being created:\n");
	create();
	printf("Linked list is created\n");
	printf("Linked list in forward direction\n");
	display();
	printf("Linked list in backward direction\n");
	display1();
	do
	{
	printf("Select any choice from below:\n");
	printf("1.Add begin 2.Add end, 3.Add at position\n4.Delete at begin, 5.Delete at end, 6.Del at position, 7.Display");	
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			addbegin();
			break;
		case 2:
			addend();
			break;
		case 3:
			addatpos();
			break;
		case 4:
			delbegin();
			break;
		case 5:
			delend();
			break;
		case 6:
			delatpos();
			break;
		case 7:
			display();
			break;
		default:
			printf("Invalid choice");	
	}
	printf("Print y to continue\n");
	scanf(" %s",&choice);
	}while(choice=='y');
}
