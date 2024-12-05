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
	int i,count;
	scanf("%d",&count);
	for(i=1;i<=count;i++)
	{
		newnode=(struct employee*)malloc(sizeof(struct employee));
		printf("Enter employee id, name, salary:\n");
		scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
		if(head==NULL)
		{
			head=newnode;
			newnode->next=head;
		}
		else
		{
			node=head;
			while(node->next!=head)
			{
				node=node->next;
			}
			node->next=newnode;
			newnode->next=head;
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
		do{
			printf("%d\t%s\t%.2f\n",node->id,node->name,node->salary);
			node=node->next;
		}while(node!=head);
	}
}
void check()
{
	node=head;
	while(node->next!=head)
	{
		node=node->next;
	}
	printf("First node address is %d\n",head);
	printf("Last node address is %d\n",node->next);
}
void addbegin()
{
	newnode=(struct employee*)malloc(sizeof(struct employee));
		printf("Enter employee id, name, salary:\n");
		scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
		if(head==NULL)
		{
			newnode->next=newnode;
			head=newnode;
		}
		else
		{
			node=head;
			while(node->next!=head)
			{
				node=node->next;
			}node->next=newnode;
			newnode->next=head;
			head=newnode;
		}
}
void addend()
{
	newnode = (struct employee*)malloc(sizeof(struct employee));		
	printf("Enter employee id, name, salary:\n");
	scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
	if(head==NULL)
	{
		head=newnode;
		newnode->next=newnode;
	}
	else
	{
		node=head;
		while(node->next!=head)
		{
			node=node->next;
		} node->next=newnode;
		newnode->next=head;
	}
}
void addatpos()
{
	int i,pos;
	newnode = (struct employee*)malloc(sizeof(struct employee));		
	printf("Enter employee id, name, salary:\n");
	scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
	printf("Enter position number:\n");
	scanf("%d",&pos);
	node=head;
	for(i=1;i<pos-1;i++)
	{
		node=node->next;
	}newnode->next=node->next;
		node->next=newnode;
}
void delbegin()
{
	if(head==NULL)
	printf("List is empty");
	else{
	node=head;
	while(node->next!=head)
	{
		node=node->next;
	}node->next=head->next;
	delnode=head;
	head=head->next;
	printf("Data of deleted node is:\n");
		printf("%d\t%s\t%f",delnode->id,delnode->name,delnode->salary);
	free(delnode);
	delnode=NULL;
}
}
void delend()
{
	if(head==NULL)
	printf("List is empty");
	else
	{
		node=head;
		while(node->next->next!=head)
		{
			node=node->next;
		}delnode=node->next;
		node->next=head;
		printf("Data of deleted node is:\n");
		printf("%d\t%s\t%f",delnode->id,delnode->name,delnode->salary);
		free(delnode);
		delnode=NULL;
	}
}
void delatpos()
{
	int pos,i;
	printf("Enter position:\n");
	scanf("%d",&pos);
	for(i=1;i<pos-1;i++)
	{
		node=node->next;
	} delnode=node->next;
	node->next=delnode->next;
	printf("Data of deleted node is:\n");
	printf("%d\t%s\t%f",delnode->id,delnode->name,delnode->salary);
	free(delnode);
	delnode=NULL;
}
int main()
{ int op;char choice;
	printf("Double linked list is being created:\n");
	create();
	printf("Linked list is created\nYour Linked List is:\n");
	display();
	check();
	do
	{
	printf("Select any choice from below:\n");
	printf("1.Add begin 2.Add end, 3.Add at position\n4.Delete begin,5.Delete at end, 6.Del at position, 7.Display");	
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
	printf("\nPrint y/Y to continue\n");
	scanf(" %s",&choice);
	}while(choice=='y'|| choice=='Y');
}
