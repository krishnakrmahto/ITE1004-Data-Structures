#include<stdio.h>
#include<stdlib.h>
typedef struct record
{
	int id;
	int day,month,year;
	int key_val;
	struct record *prev,*next;
}RECORD;
RECORD *nw,*head,*tail;
void rec_entry(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter ID: ");
		nw=(RECORD*)malloc(sizeof(RECORD));
		scanf("%d",&nw->id);
		printf("Enter day, month and year separated by space: ");
		scanf("%d%d%d",&nw->day,&nw->month,&nw->year);
		nw->key_val=i;
		nw->prev=tail;
		tail->next=nw;;
		tail=nw;
		tail->next=NULL;
	}
}
void insertion_sort(RECORD *head)
{
	RECORD *temp1,*temp2;
	int temp;
	for(temp1=head->next;temp1!=NULL;temp1=temp1->next)
	{
		for(temp2=head;temp2!=temp1;temp2=temp2->next)
		{
			if(temp2->id>temp1->id)
			{
				temp=temp2->id;
				temp2->id=temp1->id;
				temp1->id=temp;
				temp=temp2->day;
				temp2->day=temp1->day;
				temp1->day=temp;
				temp=temp2->month;
				temp2->month=temp1->month;
				temp1->month=temp;
				temp=temp2->year;
				temp2->year=temp1->year;
				temp1->year=temp;
				temp=temp2->key_val;
				temp2->key_val=temp1->key_val;
				temp1->key_val=temp;
				
			}
		}
	}
}
void selection_sort_year(RECORD *head)
{
	RECORD *temp1,*temp2;
	int temp;
	for(temp1=head;temp1->next->next!=NULL;temp1=temp1->next)
	{
		for(temp2=temp1->next;temp2!=tail;temp2=temp2->next)
		{
			if(temp1->year>temp2->year)
			{
				temp=temp1->id;
				temp1->id=temp2->id;
				temp2->id=temp;
				temp=temp1->day;
				temp1->day=temp2->day;
				temp2->day=temp;
				temp=temp1->month;
				temp1->month=temp2->month;
				temp2->month=temp;
				temp=temp1->year;
				temp1->year=temp2->year;
				temp2->year=temp;
				temp=temp1->key_val;
				temp1->key_val=temp2->key_val;
				temp2->key_val=temp;
				
			}
		}
	}
}
void selection_sort_month(RECORD *head)
{
	RECORD *temp1,*temp2;
	int temp;
	for(temp1=head;temp1->next->next!=NULL;temp1=temp1->next)
	{
		for(temp2=temp1->next;temp2!=tail;temp2=temp2->next)
		{
			if((temp1->month>temp2->month)&&(temp1->year>temp2->year))
			{
				temp=temp1->id;
				temp1->id=temp2->id;
				temp2->id=temp;
				temp=temp1->day;
				temp1->day=temp2->day;
				temp2->day=temp;
				temp=temp1->month;
				temp1->month=temp2->month;
				temp2->month=temp;
				temp=temp1->year;
				temp1->year=temp2->year;
				temp2->year=temp;
				temp=temp1->key_val;
				temp1->key_val=temp2->key_val;
				temp2->key_val=temp;
				
			}
		}
	}
}
void selection_sort_day(RECORD *head)
{
	RECORD *temp1,*temp2;
	int temp;
	for(temp1=head;temp1->next->next!=NULL;temp1=temp1->next)
	{
		for(temp2=temp1->next;temp2!=tail;temp2=temp2->next)
		{
			if((temp1->day>temp2->day)&&(temp1->month>temp2->month)&&(temp1->year>temp2->year))
			{
				temp=temp1->id;
				temp1->id=temp2->id;
				temp2->id=temp;
				temp=temp1->day;
				temp1->day=temp2->day;
				temp2->day=temp;
				temp=temp1->month;
				temp1->month=temp2->month;
				temp2->month=temp;
				temp=temp1->year;
				temp1->year=temp2->year;
				temp2->year=temp;
				temp=temp1->key_val;
				temp1->key_val=temp2->key_val;
				temp2->key_val=temp;
				
			}
		}
	}
}
int stability(RECORD *head)
{
	int flag=1;
	RECORD *temp1,*temp2;
	for(temp1=head;temp1!=NULL;temp1=temp1->next)
	{
		for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
		{
			if(temp1->day==temp2->day&&temp1->month==temp2->month&&temp1->year==temp2->year)
			{
				if(temp1->key_val<temp2->key_val)
				continue;
				else
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==0)
		break;
	}
	return(flag);
}
void printlist(RECORD *head)
{
	int i=1;
	RECORD *temp;
	puts("Sorted ID list:");
	for(temp=head;temp!=NULL;temp=temp->next)
	printf("%d. %d %d-%d-%d\n",i++,temp->id,temp->day,temp->month,temp->year);
}
int main()
{
	int i,n,choice,flag=1,stability_chk;
	char choice2;
	puts("Enter the number of older records: ");
	scanf("%d",&n);
	puts("\nEnter older records, in sorted order of ID");
	for(i=0;i<n;i++)
	{
		printf("Enter ID: ");
		nw=(RECORD*)malloc(sizeof(RECORD));
		scanf("%d",&nw->id);
		printf("Enter day, month and year separated by space: ");
		scanf("%d%d%d",&nw->day,&nw->month,&nw->year);
		nw->key_val=i;
		if(flag==1)
		{
			head=nw;
			head->prev=NULL;
			tail=nw;
			tail->next=NULL;
			flag=0;
		}
		else
		{
			nw->prev=tail;
			tail->next=nw;
			tail=nw;
			tail->next=NULL;
		}
	}
	do
	{
		puts("\n1. Enter one new record\n2. Enter multiple new records");
		puts("3. Sort according to ID (insertion sort) and check stability of algorithm");
		puts("4. Sort according to date (selection sort) and check stability of algorithm");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				rec_entry(1);
				break;
			case 2:
				puts("\nEnter the number of records: ");
				scanf("%d",&n);
				rec_entry(n);
				break;
			case 3:
				insertion_sort(head);
				puts("The algorithm is stable!");
				printlist(head);
				break;
			case 4:
				selection_sort_year(head);
				selection_sort_month(head);
				selection_sort_day(head);
				stability_chk=stability(head);
				if(stability_chk==1)
				puts("The algorithm is stable!");
				else
				puts("The algorithm is unstable!");
				printlist(head);
				break;
		}
		
	}while(choice<5);

}


