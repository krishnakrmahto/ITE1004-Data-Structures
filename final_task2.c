#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
	char *urls[20];
	int top1,top2;
}st;
void disp_forward()
{
	int i;
	for(i=st.top2;i<=19;i++)
	printf("%s\n",st.urls[i]);
}
void disp_back()
{
	int i;
	for(i=st.top1;i>=0;i--)
	printf("%s\n",st.urls[i]);
}
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
	int i,tempo=st.top2;
	char adrs[30],*temp;
	puts("\nEnter url: ");
	scanf("%s",adrs);
	temp=(char*)malloc(strlen(adrs)+1);
	strcpy(temp,adrs);
	st.urls[++st.top1]=temp;
	printf("You're in %s\n",st.urls[st.top1]);
	for(i=tempo;i<=19;i++)
	st.top2++;//on entering a new url, the forward stack should become empty because on pressing back, we can't get the initial urls which that were present in forwrd stack before the new url was inserted.
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
			puts("1. Forward\n2. Enter URL\n3. Contents of Back stack\n4. Content of Forward stack");//Back stack is where webpages which are obtained upon selecting 'Back'. Front stack is where webpages which are obtained upon selecting 'Front'.
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
			}
		}
		else if(empty2()==1 && full1()==1)
		{
			puts("1. Backward\n2. Contents of Back stack");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					back();
					break;
					case 2:
						disp_back();
						break;
			}
		}
		else if(empty2()==1 && empty1()==0 && st.top1!=0)
		{
			puts("1. Backward\n2. Enter URL\n3. Contents of Back stack");
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
			}
		}
			else if(empty1()==1)
			{
				puts("First visit! URL plz!");//after first visit, there will always be atleast one url in top1 stack as in this case neither forward,nor back possible.
				url();
			}
			else if(st.top1==0 && empty2()==1)
			{
				puts("1. Enter second page\n2. Contents of Back stack");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						url();
						break;
						case 2:
							disp_back();
							break;
				}

			}
			else
			{
				puts("1. Backward\n2. Forward\n3. Enter URL\n4. Contents of Back stack\n5. Contents of Forward stack");
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
				}
			}
			puts("Continue? Y or N");
			proceed=getche();
		}while(proceed=='Y' || proceed=='y');
	}

