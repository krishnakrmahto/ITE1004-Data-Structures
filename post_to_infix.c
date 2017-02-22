#include<stdio.h>
#include<conio.h>
#include<string.h>
struct stack
{
	char* a[25];
	int top;
}st;
void push(char* item)
{
	//check full condtion sttt.top==25
	st.a[++st.top]=item;
}
char* pop()
{
	//check empty condition
	return(st.a[st.top--]);
}
int main()
{
	st.top=-1;
	char postfix[25],*pfptr,*op1,*op2;
	puts("Enter the postfix exp: ");
	scanf("%s",postfix);
	pfptr=postfix;
	while(*pfptr!='\0')
	{
		if(isalnum(*pfptr))
		push(pfptr++);
		else
		{
			op1=pop();
			op2=pop();
			strcat(op2,strcat("*",op1));
			push(op2);
			pfptr++;
		}
	}
	printf("%s",st.a);
	return 0;
}
