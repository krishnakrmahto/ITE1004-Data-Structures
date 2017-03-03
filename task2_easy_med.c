#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
struct stack
{
	char *urls[SIZE];
	int top;
}st_fbutton,st_bbutton;//st_bbutton is the stack where user will be on pressing back button, fbutton follows same rule.
void disp_forward()
{
	int i;
	for(i=st_fbutton.top;i>=0;i--)
	printf("%s\n",st_fbutton.urls[i]);
}
void disp_back()
{
	int i;
	for(i=st_bbutton.top;i>=0;i--)
	printf("%s\n",st_bbutton.urls[i]);
}
int empty1()
{
	if(st_bbutton.top==-1)
	return 1;
	return 0;
}
int empty2()
{
	if(st_fbutton.top==-1)
	return 1;
	return 0;
}
int full1()
{
	if(st_fbutton.top==SIZE-1)
	return 1;
	return 0;
}
int full2()
{
	if(st_bbutton.top==SIZE-1)
	return 1;
	return 0;
}
void url()
{
	int i,tempo=st_fbutton.top;
	char adrs[30],*temp;
	puts("\nEnter url: ");
	scanf("%s",adrs);
	temp=(char*)malloc(strlen(adrs)+1);
	strcpy(temp,adrs);
	st_bbutton.urls[++st_bbutton.top]=temp;
	printf("You're in %s\n",st_bbutton.urls[st_bbutton.top]);
	st_fbutton.top=-1;//on entering a new url, the forward stack should become empty
	//for(i=tempo;i>;i++)
	//st_fbutton.top--;
}
void back()
{
	char item[30],*temp;
	strcpy(item,st_bbutton.urls[st_bbutton.top]);
	st_bbutton.top--;
	temp=(char*)malloc(strlen(item)+1);
	strcpy(temp,item);
	st_fbutton.urls[++st_fbutton.top]=temp;
	printf("You're in %s\n",st_bbutton.urls[st_bbutton.top]);
}
void forward()
{	
	char item[30],*temp;
	strcpy(item,st_fbutton.urls[st_fbutton.top]);
	st_fbutton.top--;
	temp=(char*)malloc(strlen(item)+1);
	strcpy(temp,item);
	st_bbutton.urls[++st_bbutton.top]=temp;
	printf("You're in %s\n",st_bbutton.urls[st_bbutton.top]);
}
int main()
{
	st_bbutton.top=-1;
	st_fbutton.top=-1;
	char proceed;
	int choice;
	do
	{
		puts("\nEnter your choice: ");
		if(st_bbutton.top==0 && empty2()==0)
		{
			puts("1. Forward\n2. Enter URL\n3. Contents of Back stack\n4. Content of Forward stack\n5. Exit");//Back stack is where webpages which are obtained upon selecting 'Back'. Front stack is where webpages which are obtained upon selecting 'Front'.
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					forward();
					break;
					case 2:
						url();
						break;
						case 3:
							disp_back();
							break;
							case 4:
								disp_forward();
								break;
								case 5:
									exit(0);
			}
		}
		else if(empty2()==1 && full1()==1)
		{
			puts("1. Backward\n2. Contents of Back stack\n3. Exit");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					back();
					break;
					case 2:
						disp_back();
						break;
						case 3:
							exit(0);
			}
		}
		else if(empty2()==1 && empty1()==0 && st_bbutton.top!=0)
		{
			puts("1. Backward\n2. Enter URL\n3. Contents of Back stack\n4. Exit");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					back();
					break;
					case 2:
						url();
						break;
						case 3:
							disp_back();
							break;
							case 4:
								exit(0);
			}
		}
			else if(empty1()==1)
			{
				puts("First visit! URL plz!");//after first visit, there will always be atleast one url in top1 stack as in this case neither forward,nor back possible.
				url();
			}
			else if(st_bbutton.top==0 && empty2()==1)
			{
				puts("1. Enter second page\n2. Contents of Back stack\n3. Exit");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						url();
						break;
						case 2:
							disp_back();
							break;
							case 3:
								exit(0);
				}

			}
			else
			{
				puts("1. Backward\n2. Forward\n3. Enter URL\n4. Contents of Back stack\n5. Contents of Forward stack\n6. Exit");
				scanf("%d",&choice);
				switch(choice)
				{
				case 1:
					back();
					break;
					case 2:
						forward();
						break;
						case 3:
							url();
							break;
							case 4:
								disp_back();
								break;
								case 5:
									disp_forward();
									break;
									case 6:
										exit(0);
				}
			}
			puts("Continue? Y or N");
			proceed=getche();
		}while(proceed=='Y' || proceed=='y');
	}


