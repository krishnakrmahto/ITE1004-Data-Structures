#include<conio.h>
#include<stdio.h>
#include<string.h>
struct queue
{
    char customers[20],total;
    int rear,front;
}lq;
int adult_num,children_num,total;
int queue_full()
{
    if(lq.rear==19)
        return 1;
    return 0;
}
int queue_empty()
{
    if(lq.rear==-1)
        return 1;
}
void right_shift(times)
{
    int i,j,temp1=lq.rear+1,temp2=lq.front;
    for(i=0;i<times;i++,temp1++,temp2++)
    {
        for(j=temp1;j>temp2;j--)
            lq.customers[j]=lq.customers[j-1];
        lq.rear=temp1;
    }
}
void vip_cust(int adults,int children)
{
	int i,temp;
    if(queue_empty()==1)
    {
        lq.front++;
        for(i=0;i<adults;i++)
        {
            adult_num++;
            lq.customers[++lq.rear]='V';//V for adult VIPs
        }
        for(i=0;i<children;i++)
        {
            children_num++;
            lq.customers[++lq.rear]='v';//v for children VIPs
        }
        puts("\nVIP family placed in front.");
        printf("The current queue is: %s",lq.customers);
    }

    else
    {
        right_shift(adults+children);
        for(i=0,temp=lq.front;i<adults;i++,temp++)
        {
            adult_num++;
            lq.customers[temp]='V';//V for adult VIPs
        }
        for(i=0;i<children;i++,temp++)
        {
            children_num++;
            lq.customers[temp]='v';//v for children VIPs
        }
        puts("\nVIP family placed in front.");
        printf("The current queue is: %s",lq.customers);
    }
}
void take_customers()
{
    int i,adults,children;
    char choice;
    puts("\nEnter the number of adults and children: ");
    scanf("%d",&adults);
    scanf("%d",&children);
    fflush(stdin);
    total=total+children+adults;
    if(total<21)
    {
    	puts("VIPs? Y or N");
    	scanf("%c",&choice);
    	if(choice=='n'||choice=='N')
    	{
        	if(queue_empty()==1)
            	lq.front++;
        	for(i=0;i<adults;i++)
        	{
            	adult_num++;
            	lq.customers[++lq.rear]='a';//a for adult
        	}
        	for(i=0;i<children;i++)
        	{
	            children_num++;
    	        lq.customers[++lq.rear]='c';//c for child
        	}
    	}
    	else if(choice=='y'||choice=='Y')
	        vip_cust(adults,children);
	    else
	    {
	    	puts("Wrong character!");
	    	return;
		}
	}
	else
    {
        puts("More than 20 not allowed!");
        total-=children+adults;
    }
}
void empty_queue()
{
    lq.customers[lq.front]='\0';
    lq.front=-1;
    lq.rear=-1;
}
int main()
{
	char choice;
    lq.rear=-1;
    lq.front=-1;
    do
    {
    	total=0;
        adult_num=0;
        children_num=0;
        for(;queue_full()==0;)
            take_customers();
        empty_queue();
        puts("\n20 customers have been sent for the ride.");
        printf("The number of adults: %d\nThe number of children: %d\n",adult_num,children_num);
        puts("\n\nReady for another round?");
        fflush(stdin);
        scanf("%c",&choice);
        puts("\n");
    }while(choice=='Y'||choice=='y');
    return 0;
}

