#include<stdio.h>
struct queue_n //new type of queue
{
	int a[5],front,rear;
}lq; //new linear queue
int lq_full()
{
	if((lq.rear+1)%5==lq.front)
	return 1;
	return 0;
}
int lq_empty()
{
	if(lq.front==-1)
	return 1;
	return 0;
}
void insert(int choice)
{
	if(lq_full()==1)
	{
		puts("Queue full!");
		return;
	}
	else
	{
		int item,i;
		puts("Enter the item you want to insert: ");
		scanf("%d",&item);
		switch(choice)
		{
			case 1:
				if(lq_empty()==1)
				{
					lq.a[++lq.rear]=item;
					lq.front++;
				}
				else
				{
					if(lq.rear==lq.front)
					{
					lq.a[lq.rear+1]=lq.a[lq.rear++];
					lq.a[lq.front]=item;
					}
					else
					{
					//	lq.a[lq.rear+1]=lq.a[lq.rear++];
						for(i=lq.rear+1;i>lq.front;i--)
						lq.a[i]=lq.a[i-1];
						lq.a[lq.front]=item;
						lq.rear++;
					}
				}break;
				case 2:
					if(lq_empty()==1)
					{
						lq.a[++lq.rear]=item;
						lq.front++;
					}
					else
					{
						lq.a[++lq.rear]=item;
					}break;
		}
	}
}
void deletion(int choice)
{
	int del_item;
	if(lq_empty()==1)
	printf("Queue is empty!\n");
	else if(choice==1)
	{
		del_item=lq.a[lq.rear];
		lq.rear--;
		if(lq.rear==-1)
		lq.front=-1;
		printf("Deleted item: %d\n",del_item);
		
	}
	else
	{
		if(lq.front<lq.rear)
		{
			del_item=lq.a[lq.front];
			lq.front++;
			printf("Deleted item: %d\n",del_item);
		}
		else
		{
			printf("%d\n",lq.a[lq.front]);
			lq.front=-1;
			lq.rear=-1;
		}
	}
}
void display(choice)
{
	if(lq_empty()==1)
	puts("Queue empty!\n");
	else
	{
		int temp;
		switch(choice)
		{
			case 1:
				temp=lq.rear;
				while(temp!=lq.front)
				{
					printf("%d\n",lq.a[temp--]);
				}
				printf("%d\n",lq.a[temp]);
				break;
				case 2:
					temp=lq.front;
					while(temp!=lq.rear)
					printf("%d\n",lq.a[temp++]);
					printf("%d\n",lq.a[temp]);
					break;
		}
	}
}
int main()
{
	int choice,action;
	lq.front=-1;
	lq.rear=-1;
	printf("Which method?\n1. Front end insertion\n2. Conventional\n ");
	scanf("%d",&choice);
	do
	{
		puts("What would you like to do?\n1. Insertion\n2. Deletion\n3. Display\n");
		scanf("%d",&action);
		switch(action)
		{
			case 1:
				insert(choice);break;
				case 2:
					deletion(choice);break;
					case 3:
						display(choice);break;
		}
	}while(action<=3);
	return 0;
}
