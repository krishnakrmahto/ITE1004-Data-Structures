#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
//one node for one student
typedef struct record
{
	char name[30];
	int roll;
}RECORD;
typedef struct node
{
	RECORD  st_rec;
	struct node *prev,*next;
}NODE;
NODE *head,*tail,*nw;
int count=1;
void create_rec(int n)
{
	int i;
	nw=(NODE*)malloc(sizeof(NODE));
	printf("Student %d\nenter roll number:\n",count++);
	scanf("%d",&nw->st_rec.roll);
	puts("enter name: ");
	scanf("%s",nw->st_rec.name);
	puts("");
	head=nw;
	head->prev=NULL;
	tail=nw;
	tail->next=NULL;
	for(i=0;i<n-1;i++)
	{
		nw=(NODE*)malloc(sizeof(NODE));
		printf("Student %d\nenter roll number: \n",count++);
		scanf("%d",&nw->st_rec.roll);
		puts("enter name: ");
		scanf("%s",nw->st_rec.name);
		tail->next=nw;
		nw->prev=tail;
		tail=nw;
		tail->next=NULL;
		puts("");
	}
}
void disp_pn(NODE *address)
{
	if(address!=head)
	printf("Previous record: %d- %s\n",address->prev->st_rec.roll,address->prev->st_rec.name);
	else
	puts("It's the first element.");
	if(address!=tail)
	printf("Next record: %d- %s\n\n",address->next->st_rec.roll,address->next->st_rec.name);
	else
	puts("It's the last element.'");
}
void insert_rec()
{
	nw=(NODE*)malloc(sizeof(NODE));
	printf("Student %d\nenter roll number: \n",count++);
	scanf("%d",&nw->st_rec.roll);
	puts("enter name: ");
	scanf("%s",nw->st_rec.name);
	tail->next=nw;
	nw->prev=tail;
	tail=nw;
	tail->next=NULL;
	puts("");
}
void search()
{
	NODE *temp;
	int roll;
	puts("\nenter the roll number: ");
	scanf("%d",&roll);
	for(temp=head;(temp->st_rec.roll!=roll)&&temp!=NULL;temp=temp->next)
	continue;
	if(temp!=NULL)
    {
        puts("Record found. It's between: ");
        disp_pn(temp);
    }
    else
        puts("Record not found!");
}
void delete_rec()
{
	NODE *temp;
	int roll;
	puts("enter the roll number: ");
	scanf("%d",&roll);
	for(temp=head;temp->st_rec.roll!=roll;temp=temp->next)
	continue;
	disp_pn(temp);
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	temp->prev=NULL;
	temp->next=NULL;
	free(temp);
}
int main()
{
	int n,choice;
	char choice2;
	puts("enter the number of students: ");
	scanf("%d",&n);
	puts("\nEnter the records: \n");
	create_rec(n);
	do
	{
		puts("enter your option:\n1. Add one more record\n2. Search for a record\n3. Delete a record\n4. exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_rec();//inserting one data at a time
				break;
			case 2:
				search();
				break;
			case 3:
				delete_rec();
				break;
			case 4:
				exit(0);
		}
		puts("\ncontinue? Y or N?");
		fflush(stdin);
		scanf("%c",&choice2);
	}while(choice2=='Y'||choice2=='y');
	return 0;
}

