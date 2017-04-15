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
void swap(RECORD *right,RECORD *left)
{
	left->next=right->next;
	right->prev=left->prev;
	left->prev=right;
	right->next=left;
	if(right->prev!=NULL)
	right->prev->next=right;//if right->prev==NULL,then this line shoulnt be used
	if(left->next!=NULL)
	left->next->prev=left;
}
void insertion_sort(RECORD *start,RECORD *end)
{
	int val_to_insert;
	RECORD *temp,*hole,*node_to_insert;
	for(temp=start->next;temp!=NULL;temp=temp->next)
	{
		val_to_insert=temp->id;
		for(hole=temp;hole!=start;hole=hole->prev)
		{
			if(hole->prev->id>val_to_insert)
			swap(hole,hole->prev);
		}
	}
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
	int i,n,choice,flag=1;
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
	puts("1. Enter one new record\n2. Enter multiple new records");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			rec_entry(1);
			break;
		case 2:
			puts("Enter the number of records: ");
			scanf("%d",&n);
			rec_entry(n);
			break;
	}
	insertion_sort(head,tail);
	printlist(head);

}

