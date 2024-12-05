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
void sort()
{
  int tempId, tempDeptno;
  char tempname[20],tempdesignation[20];
  float tempsalary;
  NP1 = head;
  while (NP1->next!=NULL)
  {
    NP2 = NP1->next;
    while(NP2!=NULL)
    {
      if(NP1->sal>NP2->sal)
      {
        tempId = NP1->id;
        strcpy(tempname,NP1->name);
        strcpy(tempdesignation,NP1->desig);
        tempsalary = NP1->sal;
        tempDeptno = NP1->deptno;
        NP1->id=NP2->id;
        strcpy(NP1->name,NP2->name);
        strcpy(NP1->desig,NP2->desig);
        NP1->deptno=NP2->deptno;
        NP1->sal=NP2->sal;
        NP2->id=tempId;
        strcpy(NP2->name,tempname);
        strcpy(NP2->desig,tempdesignation);
        NP2->deptno=tempDeptno; 
		NP2->sal=tempsalary; 
      }
      NP2=NP2->next;
    }
    NP1=NP1->next;
  }
}
int main()
{
  create();
  printf("Data before sorting \n");
  display();
  sort();
  printf("Data after sorting \n");
  display();
}
