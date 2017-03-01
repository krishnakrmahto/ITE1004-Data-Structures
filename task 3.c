#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 30
struct stack1//stack for conversion
{
	char *terms1[SIZE-10];//array to hold the characters during infix to postifx(holds operators) and postfix to prefix(holds operands)
	int top1;
}st1;
struct stack2//stack for evaluation
{
	int terms2[SIZE+10];
	int top2;
}st2;
void push_e(char item)//push to be used during eval
{
	st2.terms2[++st2.top2]=item-48;
}
int pop_e()//pop to be used during evaluation
{
	return(st2.terms2[st2.top2--]);
}
void push(char *item)
{
	st1.terms1[++st1.top1]=item;
}
char *pop()
{
	return(st1.terms1[st1.top1--]);
}
int priority(char x)
{
	switch(x)
	{
		case '-':
			return 0;
			case '+':
				return 1;
				case '*':
					return 2;
					case '/':
						return 3;

	}
}
void eval(char *postfix)
{
	char *term;
	int op1,op2;
	for(term=postfix;*term!='\0';term++)
	{
		if(isdigit(*term))
		push_e(*term);
		else
		{
			op1=pop_e();
			op2=pop_e();
			switch(*term)
			{
				case '/':
					push_e((op2/op1)+48);
					break;
					case '*':
						push_e((op2*op1)+48);
						break;
						case '+':
							push_e(op2+op1+48);
							break;
							case '-':
								push_e(op2-op1+48);
								break;
			}
		}
	}
	printf("\nThe evaluation is: %d",pop_e());
}
int main()
{
	char *term,*op_ptr,infix[SIZE+10],postfix[SIZE+10],*op,*op1,*op2,caten[SIZE];//infix stores the terms in infix notation, postfix stores the terms in postfix notation.//term holds the adress of
	//each term in the exp
	st1.top1=-1;
	st2.top2=-1;
	int j=0;//j will store the index of postfix
	//term=infix;
	printf("Enter the infix expression: ");
	scanf("%s",infix);
	//while(*term!='\0')
	for(term=infix;*term!='\0';term++)
	{
		if(isalnum(*term))
		postfix[j++]=*term;
		else if(*term=='(')
		push(term);
		else if(*term==')')
		{
			while(*st1.terms1[st1.top1]!='(')//until we get opening braces...
			postfix[j++]=*pop();//...do this
			pop();//we don't need paranthesis in a postfix, but we do need other operators! so popped operators were being collected and added to the postfix
			//array
		}
		else if(st1.top1==-1||*st1.terms1[st1.top1]=='(')
		push(term);
		else if(priority(*term)>priority(*st1.terms1[st1.top1]))
		push(term);
		else
		{
			while((st1.top1!=-1 && priority(*term)<priority(*st1.terms1[st1.top1])))
			postfix[j++]=*pop();
			push(term);
		}
		//term++;
	}
	while(st1.top1!=-1)
	postfix[j++]=*pop();
	postfix[j]='\0';
	printf("\nThe postfix of the given prefix is: %s",postfix);
/*-------------------------------------------------------*postfix conversion ends------------------------------------------*/

/*-------------------------------------------------------*prefix conversion starts-----------------------------------------*/

	//now term will be used to iterate through the postfix exp for prefix conversion
	int opind=0;
	for(term=postfix;*term!='\0';term++)
	{
		op=(char*)malloc(SIZE+1);
		//strcpy(op_ptr,op);
		if(isalnum(*term))
		push(term);
		else
		{
			switch(*term)
			{
				case '+':
					op[opind++]='+';
					op[opind++]='\0';//doing this because rest of the indices of op will have some garbage characters.terminating the string op...
					//means op string has ended, no other garbage values.
					op1=pop();
					op2=pop();
					if(isalnum(*op2))
					sprintf(caten,"%c",*op2);
					else
					sprintf(caten,"%s",op2);
					strcat(op,caten);
					if(isalnum(*op1))
					sprintf(caten,"%c",*op1);
					else
					sprintf(caten,"%s",op1);
					strcat(op,caten);
					push(op);
					opind=0;
					break;
					case '-':
						op[opind++]='-';
						op[opind++]='\0';
						op1=pop();
						op2=pop();
						if(isalnum(*op2))
						sprintf(caten,"%c",*op2);
						else
						sprintf(caten,"%s",op2);
						strcat(op,caten);
						if(isalnum(*op1))
						sprintf(caten,"%c",*op1);
						else
						sprintf(caten,"%s",op1);
						strcat(op,caten);
						push(op);
						opind=0;
						break;
						case '*':
							op[opind++]='*';
							op[opind++]='\0';
							op1=pop();
							op2=pop();
							if(isalnum(*op2))
							sprintf(caten,"%c",*op2);
							else
							sprintf(caten,"%s",op2);
							strcat(op,caten);
							if(isalnum(*op1))
							sprintf(caten,"%c",*op1);
							else
							sprintf(caten,"%s",op1);
							strcat(op,caten);
							push(op);
							opind=0;
							break;
							case '/':
								op[opind++]='/';
								op[opind++]='\0';
								op1=pop();
								op2=pop();
								if(isalnum(*op2))
								sprintf(caten,"%c",*op2);
								else
								sprintf(caten,"%s",op2);
								strcat(op,caten);
								if(isalnum(*op1))
								sprintf(caten,"%c",*op1);
								else
								sprintf(caten,"%s",op1);
								strcat(op,caten);
								push(op);
								opind=0;
								break;
			}
		}
	}
while(st1.top1!=-1)
{
    char *prefix;
    prefix=pop();
    printf("\nThe prefix is: %s",prefix);
}
eval(postfix);
return 0;
}

