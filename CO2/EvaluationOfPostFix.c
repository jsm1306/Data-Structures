#include<stdio.h>
#include<math.h>
int stack[20];
int top=-1;
void push(int value)
{
	stack[++top]=value;
}
int pop()
{
	return stack[top--];
}
void main()
{
	char postfix[20],x;
	int i,op1,op2;
	printf("Enter any postfix expression using digits");
	scanf("%s",&postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		x=postfix[i];
		if(x>='0'&& x<='9')
		push(x-48);
		else
		{
			op2=pop();
			op1=pop();
			if(x=='+')
			push(op1+op2);
			else if(x=='-')
			push(op1-op2);
			else if(x=='*')
			push(op1*op2);
			else if(x=='/')
			push(op1/op2);
			else if(x=='%')
			push(op1%op2);
			else if(x=='^')
			push(pow(op1,op2));
		}
	} printf("Result is %d",pop());
}
