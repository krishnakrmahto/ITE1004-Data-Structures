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
void push(char *item)
{
	#ifndef EVAL
	st1.terms1[++st1.top1]=item;
	#else
	st2.terms2[++st2.top2]=*item-48;
	#endif
}
#ifdef EVAL
char pop()
#endif
#ifndef EVAL
char* pop()
#endif
{
	#ifndef EVAL
	return(st1.terms1[st1.top1--]);//while post to prefix, a string might be there in the stack, so returning the pointer to the string/char
	#else
	return(st2.terms2[st2.top2--+48]);
	#endif
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
int main()
{
	char *term,infix[SIZE+10],postfix[SIZE+10],op[SIZE],*op1,*op2,caten[SIZE];//infix stores the terms in infix notation, postfix stores the terms in postfix notation.//term holds the adress of
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
			while((priority(*term)<priority(*st1.terms1[st1.top1]))&&st1.top1!=-1)
			postfix[j++]=*pop();
			push(term);
		}
		//term++;
	}
	while(st1.top1!=-1)
	postfix[j++]=*pop();
	postfix[j]='\0';
	printf("The postfix of the given prefix is: %s",postfix);
/*-------------------------------------------------------*postfix conversion ends------------------------------------------*/

/*-------------------------------------------------------*prefix conversion starts-----------------------------------------*/

	//term=postfix;//now term will be used to iterate through the postfix exp for prefix conversion
	int opind=0;//index for op1 and op2 strings and op
	//#define FIRST
	for(term=postfix;*term!='\0';term++)
	{
		if(isalnum(*term))
		push(term);
		else
		{
			switch(*term)
			{
				case '+':
					op[opind++]='+';
					op1=pop();
					op2=pop();
				/*	#ifdef FIRST
					sprintf(caten,"%c",*op2)
					strcat(op,caten);
					sprintf(caten,"%c",*op1);
					strcat(op,caten);
					push(op);
					#endif
					#undef FIRST*/
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
					//push(op);//passing the address of op..read the comment on the line that follows second after this line...
					//opind=0;
					//sprintf(op,"%c",'\0');//...now that i am overwriting the value at op with null, i will be left with EMPTINESS at st.terms1[0]
				//	free(op);
					/*for(opind=1;opind<=2;opind++)
					op[opind]=*pop();
					push(op);
					opind=0;*/
					break;
					case '-':
						op[opind++]='-';
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
						push(&op[opind]);
						//push(op);
						//opind=0;
						//sprintf(op,"%c",'\0');
					//	free(op);
						break;
						case '*':
							op[opind++]='*';
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
							push(&op[opind]);
							//push(op);
							//opind=0;
							//sprintf(op,"%c",'\0');
							//free(op);
							break;
							case '/':
								op[opind++]='/';
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
								push(&op[opind]);
								//push(op);
								//opind=0;
								//sprintf(op,"%c",'\0');
							//	free(op);
								break;
			}
		}
	}
while(st1.top1!=-1)
{
    char *prefix=pop();
    printf("\nThe prefix is: %s",prefix);
}
return 0;
}
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
void push(char *item)
{
	#ifndef EVAL
	st1.terms1[++st1.top1]=item;
	#else
	st2.terms2[++st2.top2]=*item-48;
	#endif
}
#ifdef EVAL
char pop()
#endif
#ifndef EVAL
char* pop()
#endif
{
	#ifndef EVAL
	return(st1.terms1[st1.top1--]);//while post to prefix, a string might be there in the stack, so returning the pointer to the string/char
	#else
	return(st2.terms2[st2.top2--+48]);
	#endif
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
int main()
{
	char *term,infix[SIZE+10],postfix[SIZE+10],op[SIZE],*op1,*op2,caten[SIZE];//infix stores the terms in infix notation, postfix stores the terms in postfix notation.//term holds the adress of
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
			while((priority(*term)<priority(*st1.terms1[st1.top1]))&&st1.top1!=-1)
			postfix[j++]=*pop();
			push(term);
		}
		//term++;
	}
	while(st1.top1!=-1)
	postfix[j++]=*pop();
	postfix[j]='\0';
	printf("The postfix of the given prefix is: %s",postfix);
/*-------------------------------------------------------*postfix conversion ends------------------------------------------*/

/*-------------------------------------------------------*prefix conversion starts-----------------------------------------*/

	//term=postfix;//now term will be used to iterate through the postfix exp for prefix conversion
	int opind=0;//index for op1 and op2 strings and op
	//#define FIRST
	for(term=postfix;*term!='\0';term++)
	{
		if(isalnum(*term))
		push(term);
		else
		{
			switch(*term)
			{
				case '+':
					op[opind++]='+';
					op1=pop();
					op2=pop();
				/*	#ifdef FIRST
					sprintf(caten,"%c",*op2)
					strcat(op,caten);
					sprintf(caten,"%c",*op1);
					strcat(op,caten);
					push(op);
					#endif
					#undef FIRST*/
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
					//push(op);//passing the address of op..read the comment on the line that follows second after this line...
					//opind=0;
					//sprintf(op,"%c",'\0');//...now that i am overwriting the value at op with null, i will be left with EMPTINESS at st.terms1[0]
				//	free(op);
					/*for(opind=1;opind<=2;opind++)
					op[opind]=*pop();
					push(op);
					opind=0;*/
					break;
					case '-':
						op[opind++]='-';
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
						push(&op[opind]);
						//push(op);
						//opind=0;
						//sprintf(op,"%c",'\0');
					//	free(op);
						break;
						case '*':
							op[opind++]='*';
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
							push(&op[opind]);
							//push(op);
							//opind=0;
							//sprintf(op,"%c",'\0');
							//free(op);
							break;
							case '/':
								op[opind++]='/';
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
								push(&op[opind]);
								//push(op);
								//opind=0;
								//sprintf(op,"%c",'\0');
							//	free(op);
								break;
			}
		}
	}
while(st1.top1!=-1)
{
    char *prefix=pop();
    printf("\nThe prefix is: %s",prefix);
}
return 0;
}

