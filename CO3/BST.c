#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* right;
	struct node* left;
	int data;
};
typedef struct node node;
node *root=NULL;
void create()
{
	node *t, *temp, *temp1;
	int x,choice;
	do
	{
		t=(node *)malloc(sizeof(node));
	printf("Enter data to insert:");
	scanf("%d",&x);
	t->data=x;
	t->right=NULL;
	t->left=NULL;
	if(root==NULL)
		root=t;
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			temp1=temp;
			if(t->data>temp->data)
			{
				temp=temp->right;
			}
			else
			{
				temp=temp->left;
			}
		} 
		if(t->data<temp1->data)
		temp1->left=t;
		else
		temp1->right=t;
	}
	printf("To continue: Press 1 else Press 0;");
	scanf("%d",&choice);
	}while(choice!=0);
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
	create();
	printf("\nInorder: ");
	inorder(root);
		printf("\nPreorder: ");
		preorder(root);
			printf("\nPostorder: ");
			postorder(root);
}
