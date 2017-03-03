#include<stdio.h>
#include<string.h>
void listreg_push();
void listreg_pop();
void listreg_lastsub();
void listreg_first10();
void listreg_substatus();
struct stack
{
	char reg[70][12];
	int top;
};
struct stack listreg; 
int main()
{
	int choice;
	listreg.top=-1;
	do
	{
	printf("Enter your choice:\n1. Push\n2. Pop\n3. Display last submitted entry\n4. Display first 10 submissions\n5. Check whether submitted or not\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			listreg_push();
			break;
			case 2:
				listreg_pop();
				break;
				case 3:
					listreg_lastsub();
					break;
					case 4:
						listreg_first10();
						break;
						case 5:
							listreg_substatus();
							break;
			
	}}while(choice<6);
}
void listreg_push()
{
	if(listreg_full()==1)
	printf("Stack overflow.\n\n");
	else
	{
		printf("Enter the registration number: ");
		scanf("%s",listreg.reg[++listreg.top]);
	}
}
void listreg_pop()
{
	char del_item[12];
	if(listreg_empty()==1)
	printf("Stack underflow.\n\n");
	else
	{
		strcpy(del_item,listreg.reg[listreg.top]);
		listreg.top--;
		printf("The deleted item is: %s\n",del_item);
	}
}
int listreg_full()
{
	if(listreg.top==69)
	return 1;
	else
	return 0;
}
int listreg_empty()
{
	if(listreg.top==-1)
	return 1;
	else
	return 0;
}
void listreg_lastsub()
{
	if(listreg_empty()==1)
	printf("Stack underflow.\n\n");
	else
	printf("The last submission: %s\n",listreg.reg[listreg.top]);
}

void listreg_first10()
{
	int temp;
	if(listreg_empty()==1)
	printf("Stack underflow.\n\n");
	else
	{
		temp=listreg.top;
		if(temp>=9)
		{
			temp=0;
			while(temp<=9)
			{
				printf("%s\n",listreg.reg[temp]);
				temp++;
			
			}
		}
		else
		{
			temp=0;
			while(temp<=listreg.top)
			{
				printf("%s\n",listreg.reg[temp]);
				temp++;
			}
		}
		
		}
	}


void listreg_substatus()
{
	char temp[20];
	int i;
	if(listreg_empty()==1)
	printf("Stack underflow.\n\n");
	else
	{
	printf("Enter registration number: ");
	scanf("%s",temp);
	for(i=0;i<=listreg.top;i++)
	{
		if(strcmp(temp,listreg.reg[i])!=0)
		continue;
		else
		printf("%s has submitted the assignment.\n\n",temp);
		break;
	}
	if(i>listreg.top)
	printf("%s has not submitted.\n\n",temp);
}
}
