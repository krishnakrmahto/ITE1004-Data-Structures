#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
	char *urls[20];
	int top1,top2;
}st;
int empty1()
{
	if(st.top1==-1)
	return 1;
	return 0;
}
int empty2()
{
	if(st.top2==20)
	return 1;
	return 0;
}
int full1()
{
	if(st.top1==9)
	return 1;
	return 0;
}
int full2()
{
	if(st.top2==10)
	return 1;
	return 0;
}
void url()
{
	char adrs[30],*temp;
	puts("\nEnter url: ");
	scanf("%s",adrs);
	temp=(char*)malloc(strlen(adrs)+1);
	strcpy(temp,adrs);
	st.urls[++st.top1]=temp;
	printf("You're in %s\n",st.urls[st.top1]);
}
void back()
{
	char item[30],*temp;
	strcpy(item,st.urls[st.top1]);
	st.top1--;
	temp=(char*)malloc(strlen(item)+1);
	strcpy(temp,item);
	st.urls[--st.top2]=temp;
	printf("You're in %s\n",st.urls[st.top1]);
}
void forward()
{	char item[30],*temp;
	strcpy(item,st.urls[st.top2]);
	st.top2++;
	temp=(char*)malloc(strlen(item)+1);
	strcpy(temp,item);
	st.urls[++st.top1]=temp;
	printf("You're in %s\n",st.urls[st.top1]);
}
int main()
{
	st.top1=-1;
	st.top2=20;
	char proceed;
	int choice;
	do
	{
		puts("\nEnter your choice: ");
		if(st.top1==0 && empty2()==0)
		{
			puts("1. Forward\n2. Enter URL");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					forward();
					break;
					case 2:
						url();
						break;
			}
		}
		else if(empty2()==1 && full1()==1)
		{
			puts("Backward? Y or N");
			if(getche()=='Y')
			back();
		}
		else if(empty2()==1 && empty1()==0 && st.top1!=0)
		{
			puts("1. Backward\n2. Enter URL");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					back();
					break;
					case 2:
						url();
						break;
			}
		}
			else if(empty1()==1)
			{
				puts("First visit! URL plz!");
				url();
			}
			else if(st.top1==0 && empty2()==1)
			{
				puts("URL of the second page plz!");
				url();
			}
			else
			{
				puts("1. Backward\n2. Forward\n3. Enter URL");
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
				}
			}
			puts("Continue? Y or N");
			proceed=getche();
		}while(proceed=='Y' || proceed=='y');
	}
