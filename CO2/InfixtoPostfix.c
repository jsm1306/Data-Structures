#include<stdio.h>
char stack[100];
int top=-1;
void push(char s)
{
	stack[++top]=s;
}
char pop()
{
	return stack[top--];
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int precedence(char o)
{
	if(o=='+'||o=='-')
	return 1;
	else if(o=='*'||o=='/'||o=='%')
	return 2;
	else if(o=='^')
	return 3;
}
void main()
{
	char infix[50],postfix[50],x,o;
	int i,ind=0;
	printf("Enter any infix expression\n");
	scanf(" %s",&infix);
	for(i=0;infix[i]!='\0';i++)
	{
		x=infix[i];
		if(x=='(')
		{
			push(x);
		}
		else if((x>='a' && x<='z')||(x>='A' && x<='Z'))
		{
			postfix[ind++]=x;
		}
		else if(x==')')
		{
			while((o=pop())	!='(')
			{
				postfix[ind++]=o;
			}
		}
		else
		{
			while(precedence(stack[top])>=precedence(x))
			{
				postfix[ind++]=pop();
			} push(x);
		}
	}
	while(!isempty())
	{
		postfix[ind++]=pop();
	} 
	printf("PostFix Expression is %s",postfix);
}
