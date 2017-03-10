#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#define SIZE 5
struct queue
{
	int a[SIZE],front,rear;
}cq;
int burning()//same as deletion, as per the question it should be invoked once the queue is full.
{
	int data;//burnt/deleted (from the buf) being named as data to suit the context
	if(cq.rear==cq.front)
	{
		data=cq.a[cq.front];//although both cq.rear and cq.front point to same elem, front has been conventionally used for del oper.
		cq.rear=-1;
		cq.front=-1;
		return(data);
	}
	//else: no need of else for if condition is true, control is already being "returned" there.
	data=cq.a[cq.front];
	cq.front=(cq.front+1)%SIZE;
	return(data);
	}
int cq_emp()
{
	if(cq.rear==-1)
	return 1;
	return 0;
}
int cq_full()
{
	if(cq.front==(cq.rear+1)%SIZE)
	return 1;
	return 0;
}
void display_old_buf()
{
	int i;
	puts("\nOld Buffer:");
	for(i=cq.front;i!=cq.rear;i=(i+1)%SIZE)
	printf("%d\n",cq.a[i]);
}
void display_new_buf()
{
	int i;
	puts("\nBuffer:");
	for(i=cq.front;i!=cq.rear;i=(i+1)%SIZE)
	printf("%d\n",cq.a[i]);
	printf("%d\n",cq.a[i]);
}
int writing()//same as insertion with a small modification
{
    char further;
	int data,i;
	puts("\nEnter data to be burnt: ");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d",&data);
		if(cq_emp()==1)
		{
			cq.rear=(cq.rear+1)%SIZE;
			cq.front=(cq.front+1)%SIZE;
			cq.a[cq.rear]=data;
		}
		else
		{
			cq.rear=(cq.rear+1)%SIZE;
			cq.a[cq.rear]=data;
 			if(cq_full()==1)
			{
				printf("Buffer is full, burning process is going on...\nFront= %d		Rear= %d",cq.front,cq.rear);
				printf("\nOne data burnt.\nBurnt data: %d\n",burning());
				do
				{
					printf("\n\n1. Fill more data into the buffer.\n2. Read remaining Buffer.\n3. Continue Burning.\n4. No more data to burn.\n5. Old Buffer\n	Front=%d		Rear=%d\n	Latest buffer item:%d\n",cq.front,cq.rear,cq.a[cq.rear]);
					further=getche();
					puts("");
					switch(further)
					{
                	case '1':
	                    writing();
    	            case '4':
        	        	puts("\nBurning all the data in buffer...");
            	    	display_new_buf();
                		cq.rear=-1;
                		cq.front=-1;
                		puts("\nBurning process finished.");
                		exit(2);
                	case '2':
                		display_new_buf();
                		break;
                	case '3':
                		if(cq_emp()==1)
                		puts("Burning process finished.");
                		else
                		{
                			printf("Burnt data: %d",burning());
                			break;
                		}
                	case '5':
                		display_old_buf();
                		break;
             		default:
             			exit(0);
					}
				}while(further<'6');
			}
		}
	}
}
int main()
{
    cq.rear=-1;
    cq.front=-1;
    writing();
	return 0;
}

