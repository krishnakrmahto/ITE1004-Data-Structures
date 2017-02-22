#define SIZE 20
#include<stdio.h>
#include<ctype.h>
struct stack
{
	int a[SIZE],top;
}st;
void push(int item)
{
	//routine check for full condition
	st.a[++st.top]=item;
}
int pop()
{
	int item=st.a[st.top--];
	return(item);
}
int main()
{
	int op1,op2;
	st.top=-1;
	char postfix[SIZE],*term;
	puts("Enter the postfix expression: ");
	scanf("%s",postfix);
	term=postfix;
	while(*term!='\0')
	{
		if(isdigit(*term))
		push(*term-48);//since stack has an int array, *term's ascii value would be stored in the array of the stack. subtracting 48 and then passing stores the number itself.
		else//if not digit then *term must be an operator
		{
			op1=pop(); //first popped item
			op2=pop();//second popped item
			switch(*term)
			{
				case '+':
					push(op2+op1);
					break;
					case '-':
						push(op2-op1);
						break;
						case '*':
							push(op2*op1);
							break;
							case '/':
								push(op2/op1);
								break;
			}
		}
		term++;
	}
	while(st.top!=-1)
		printf("%d",pop());
		return 0;
}
