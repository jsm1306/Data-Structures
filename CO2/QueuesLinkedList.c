#include<stdio.h>
#include<stdlib.h>//add end, del begin
struct Employee
{
  int id;
  char name[20];
  float salary;
  struct Employee *next;
}*Head,*Node,*Newnode,*Delnode;
void create()
{
  int i,n;
  printf("Enter nodes ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    Newnode = (struct Employee*)malloc(sizeof(struct Employee));
    printf("Enter employee %d details ",i);
    scanf("%d %s %f",&Newnode->id,&Newnode->name,&Newnode->salary);
    
    if(Head == NULL)
    {
        Head = Newnode; 
		Newnode->next = NULL; 
    }
      else
      {
        Node = Head;
        while(Node->next!=NULL){
          Node = Node->next;
      }
        Node->next = Newnode;
        Newnode->next = NULL;
    }
  }
}
void display()
{
  if(Head == NULL)
   printf("List is empty");
  else
  {
     Node = Head;
     while(Node!=Head)
     {
         printf("%d\t%s\t%.2f\n",Node->id,Node->name,Node->salary);
         Node = Node->next;
    }
  }
}
void Enqueue()
{
  Newnode = (struct Employee*)malloc(sizeof(struct Employee));
  printf("Enter employee  details ");
  scanf("%d %s %f",&Newnode->id,&Newnode->name,&Newnode->salary);
  Newnode->next = NULL;
  if(Head == NULL)
   Head = Newnode;
  else
  {
    Node = Head;
    while(Node->next!=NULL)
      Node = Node->next;
    Node->next = Newnode;
  }
}
void Dequeue()
{
  if(Head == NULL)
    printf("Queue is empty");
  else
  {
    Delnode = Head;
    Head = Head->next;
    free(Delnode);
    Delnode = NULL;
    printf("First node is deleted");
  }
}
void peep()
{
  int t,f=0;
  if(Head == NULL)
    printf("Queue is empty");
  else
  {
    printf("Enter employee id ");
    scanf("%d",&t);
    Node = Head;
    while(Node!=NULL)
    {
      if(t == Node->id)
      {
        printf("%d\t%s\t%f\n",Node->id,Node->name,Node->salary);
        f=1;
        break;
      }
      Node = Node->next; 
    }
    if(!f)
      printf("Employee id not found");
  }
}
int main()
{
  int op;
  char ch;
  create();
  do
  {
    printf("1.Enqueue\n2.Dequeue\n3.Search\n4.Display\n");
    printf("Enter your option");
    scanf("%d",&op);
    switch(op)
    {
      case 1:Enqueue();
      break;
      case 2:Dequeue();
      break;
      case 3:peep();
      break;
      case 4:display();
      break;
      default:printf("Enter correct choice");
    }
    printf("Enter Y,y to continue");
    scanf("%s",&ch);
  }while(ch == 'y'||ch == 'Y');
}
