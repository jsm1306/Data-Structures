#include<stdio.h>
char bstack[100];
int top=-1;
int max=100;
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void push(char o)
{
	bstack[++top]=o;
}
char pop()
{
	return bstack[top--];
}
void main()
{
	char expr[100],x,o;
	int i, balanced=1;
	printf("Enter any expression\n");
	scanf("%s",&expr);
	for(i=0;expr[i]!='\0';i++)
	{
		x=expr[i];
		if(x=='('||x=='{'||x=='[')
		push(x);
		else
		{
			o=pop();
			if(o=='(' && x!=')'||o=='{' && x!='}' || o=='[' && x!=']')
			{
				//printf("Not Balanced");
				balanced=0;
				break;
			}
			}	
	}
	if(balanced && isempty())
	printf("Balanced");
	else
	printf("Not Balanced");
}
