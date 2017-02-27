#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE1 20
#define SIZE2 50
struct stack
{
	char a[SIZE1];
	int top;
}st;
void push(char item)
{
	st.a[++st.top]=item;
}
char pop()
{
	char item;
	return(item=st.a[st.top--]);
}
int main()
{
	st.top=-1;
	int temp=0;
	char infix[SIZE2],*term;
//do
//{
	puts("\nEnter the infix that you want to check: ");
	scanf("%s",infix);
	term=infix;
	if(isalnum(*term))
	temp=1;
	else if(*term=='(')
	push(*term);
	else
	{
		puts("invalid infix.");
		exit(1);
	}
	for(term=infix+1;*term!='\0';term++)
	{
		if(temp==0)
		{
			if(isalnum(*term))
			{
				temp=1;
				continue;
			}
			else if(*term=='(')
			{
				push(*term);
				continue;
			}
			else
			{
				puts("invalid infix.");
				exit(2);
			}
			
		}
		else
		{
			if((*term=='/') || (*term=='*')||(*term=='+')||(*term=='-'))
			{
				temp=0;
				continue;
			}
			else if(*term==')')
			{
				if(pop()=='(')
				continue;
				else
				{
					puts("invalid infix");
					exit(3);
				}
			}
			else
			{
				puts("invalid infix.");
				exit(4);
			}
		}
	}
	if(st.top==-1)
	puts("valid infix.");
	else
	puts("invalid infix.");
	puts("more infixes? Y or N");
//}while((getche()=='y')||(getche()=='Y'));
	return 0;
}
