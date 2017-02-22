#include<stdlib.h>
#include<stdio.h>
#define SIZE 30
struct stack
{
	char a[SIZE];
	int top;
}st;
void push(char item)
{
	st.a[++st.top]=item;
}
char pop()
{
	return(st.a[st.top--]);
}
int main()
{
	st.top=-1;
	char infix[SIZE],*term;
	puts("Enter an infix: ");
	scanf("%s",infix);
//	term=infix;
	for(term=infix;*term!='\0';term++)//mast hai for loop.. :D
	{
		if(*term=='(' || *term=='{' || *term=='[')
		{
			push(*term);
		//	term++;
		}
		else if(*term==')')
		{
			if(pop()=='(')
			continue;
			//term++;
			else
			{
			puts("unbalanced infix");
			exit(1);
			}
			
		}
		else if(*term==']')
		{
			if(pop()=='[')
			continue;
			//term++;
			else
			{
				puts("unbalanced infix");
				exit(1);
			}
		}
		else if(*term=='}')
		{
			if(pop()=='{')
			continue;
			//term++;
			else
			{
				puts("unbalanced infix");
				exit(1);
			}
		}
		//term++;
	}
	if(st.top==-1)
	puts("balanced");
	else
	puts("unbalanced");
}
