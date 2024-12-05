#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void addbegin();
void addend();
void addpos();
void delbegin();
void delend();
void delpos();
struct movie
{
	char mname[50],ml[20],fl[20],dir[20];
	int yor;
	float rating;
	struct movie *next;
}*head,*node,*newnode,*delnode;
int main()
{
	int op;
	char choice;
	printf("Movie list is being created\n");
	create();
	printf("Movie list is created succcesfully");
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
			addpos();
			break;
		case 4:
			delbegin();
			break;
		case 5:
			delend();
			break;
		case 6:
			delpos();
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
void create()
{
	int i,c;
	printf("Enter number of movies to be added\n");
	scanf("%d",&c);
	for(i=1;i<=c;i++)
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
void addbegin()
{
		newnode=(struct movie*)malloc(sizeof(struct movie));
		printf("Enter Movie Details:\n");
		scanf(" %s %s %s %s %d %f",&newnode->mname,&newnode->ml,&newnode->fl,&newnode->dir,&newnode->yor,&newnode->rating);
		if(head==NULL)
		{
			newnode->next=NULL;
		}
		else
		{
			newnode->next=head;
		} head=newnode;
}
void addend()
{
	newnode=(struct movie*)malloc(sizeof(struct movie));
		printf("Enter Movie Details:\n");
		scanf(" %s %s %s %s %d %f",&newnode->mname,&newnode->ml,&newnode->fl,&newnode->dir,&newnode->yor,&newnode->rating);
		head=newnode;
		node=head;
		while(node->next!=NULL)
		{
			node=node->next;
		}
		node->next=newnode;
		newnode->next=NULL;
}
void addpos()
{
	int pos,i;
	newnode=(struct movie*)malloc(sizeof(struct movie));
		printf("Enter Movie Details:\n");
		scanf(" %s %s %s %s %d %f",&newnode->mname,&newnode->ml,&newnode->fl,&newnode->dir,&newnode->yor,&newnode->rating);
		printf("Enter node position:\n");
		scanf("%d",&pos);
		node=head;
		if (pos==1)
		{
			head=newnode;
			newnode->next=node;
		}
		for(i=1;i<pos-1;i++)
		{
			node=node->next;
		}
		newnode->next=node->next;
		node->next=newnode;
	}
void delbegin()
{
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else{
		delnode=head;
		head=delnode->next;
		free(delnode);
		delnode=NULL;
	}
}
void delend()
{
	if(head==NULL){
		printf("List is empty\n");
	}
	else{
		node=head;
		while(node->next->next!=NULL){
			node=node->next;
		}delnode=node->next;
		node->next=NULL;
		free(delnode);
		delnode=NULL;
	}
}
void delpos()
{
	int i,pos;
	if(head==NULL){
		printf("LIst is empty\n");
	}
	else{
		printf("Enter node position to delete\n");
		scanf("%d",&pos);
		node=head;
		for(i=1;i<pos-1;i++)
		{
			node=node->next;
		}delnode=node->next;
		node->next=delnode->next;
		printf(" %s Movie is deleted\n",delnode->mname);
		delnode=NULL;	
	}
}
void display()
{
	if(head==NULL){
		printf("LIst is empty\n");
	}
	else{
		node=head;
		while(node!=NULL)
		{
			printf(" %s\t %s\t %s\t %s\t %d\t %.2f\n",node->mname,node->ml,node->fl,node->dir,node->yor,node->rating);
			node=node->next;
		}	
	}
}		
