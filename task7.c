#include<stdio.h>
struct queue
{
	char a[20];
	int rear,front;
}lq;

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
void insert(char item)
{
	if(lq_empty()==1)
	{
		lq.a[++lq.rear]=item;
		lq.front++;
	}
	else
		lq.a[++lq.rear]=item;
}
void deletion()//don't need to return anything in the context of the question
{
	if(lq_empty()==1)
	puts("queue is empty!");
	else if(lq.rear==lq.front)
	{
		lq.rear=-1;
		lq.front=-1;
	}
	else
	lq.front++;
}
void vip_insertion(int tot_child,int tot_adult)
{
	int temp=lq.front,i;
	for(i=0;i<(tot_child+tot_adult);i++)
	{
		for(i=lq.rear+1;i>lq.front;i--)//right...
		lq.a[i]=lq.a[i-1];//...shift
	}
	for(i=0;i<tot_child;i++)
	lq.a[temp++]='c';//post-increment because tempis set to lq.front and not to -1.
	for(i=0;i<tot_adult;i++)
	lq.a[temp++]='a';
}
int take_customers(int total)
{
	int i=0;
	unsigned int children,adult,tot_child=0,tot_adult=0;
	//do
	//{
		puts("\nEnter the number of children and adults: ");
		scanf("%u%u",&children,&adult);
		tot_child+=children;
		tot_adult+=adult;
		if((tot_child+tot_adult+total)>20)
            return(tot_child+tot_adult+1);
		puts("VIPs? Y or N");
		if(getche()=='Y' || getche()=='y')
		vip_insertion(tot_child,tot_adult);
		else //insert normally
		{
			for(i=0;i<children;i++)
			insert('c');
			for(i=0;i<adult;i++)
			insert('a');
		}
	//}//while((tot_child+tot_adult)!=20);
	return(tot_adult+tot_child);
	//while(lq.front<=lq.rear)
	//deletion();
}
int main()
{
	int total=0,return_value;
	lq.front=-1;
	lq.rear=-1;
	do
	{
		do
		{
			return_value=take_customers();
			if(return_value==tot_child+tot_adult+total+1)
			{
				printf("%d people added to the next queue.",(total+tot_adult+tot_child-20));
				total=total+tot_adult+tot_child-20;
				continue;
			}
			else
			total+=return_value;
			//total+=take_customers(total);
			//puts("One more round? Y or N?");
		}while(total<20);//while(getche()=='Y' || getche()=='y');
	
	while(lq.front!=lq.rear)
	deletion();
	lq.front=-1;
	lq.rear=-1;
	puts("More rounds? Y or N");
	}while(getche()=='Y' || getche()=='y');
}

