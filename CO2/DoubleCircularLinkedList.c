#include<stdio.h>
#include<stdlib.h>
struct Employee
{
  int id;
  char name[20];
  float salary;
  struct Employee *next,*prev;
}*head,*newnode,*node;
void create()
{
  int i,n;
  printf("Enter nodes ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    newnode = (struct Employee*)malloc(sizeof(struct Employee));
    printf("Enter employee  details ");
    scanf("%d %s %f",&newnode->id,&newnode->name,&newnode->salary);
    if(head == NULL)
        head =newnode;  
      else
      {
        node = head;
        while(node->next!=head)
           node = node->next;
           node->next = newnode;
             newnode->prev = node;  
      }
    newnode->next = head;
    head->prev = newnode;
  }
}
void display()
{
  if(Head == NULL)
   printf("List is empty");
  else
  {
     node = head;
     do
     {
         printf("%d\t%s\t%.2f\n",node->id,node->name,node->salary);
         node = node->next;
    }while(node!=head);
  }
}
void delbegin()
{
	if(head==NULL)
	printf("List is empty");
	else
	{
		delnode=head;
		
		
	}
}
int main()
{
  printf("Double linked list is Creating\n");
  create();
  printf("List is created Successfully\n");
  printf("\nList in forward direction\n");
  display();
}

