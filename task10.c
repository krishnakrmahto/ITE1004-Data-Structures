#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
//one node for one student
typedef struct record
{
	char name[30];
	int role;
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
	printf("Student %d\nEnter Role Number:\n",count++);
	scanf("%d",&nw->st_rec.role);
	puts("enter name: ");
	scanf("%s",nw->st_rec.name);
	puts("");
	head=nw;
	head->prev=NULL;
	tail=nw;
	tail->next=head;
	for(i=0;i<n-1;i++)
	{
		nw=(NODE*)malloc(sizeof(NODE));
		printf("Student %d\nenter role number: \n",count++);
		scanf("%d",&nw->st_rec.role);
		puts("enter name: ");
		scanf("%s",nw->st_rec.name);
		tail->next=nw;
		nw->prev=tail;
		tail=nw;
		tail->next=head;
		puts("");
	}
}
void disp_pn(NODE *address)
{
	if(address!=head)
	printf("Previous record: %d- %s\n",address->prev->st_rec.role,address->prev->st_rec.name);
	else
	puts("It's the first element.");
	if(address!=tail)
	printf("Next record: %d- %s\n\n",address->next->st_rec.role,address->next->st_rec.name);
	else
	puts("It's the last element.'");
}
void insert_rec()
{
	nw=(NODE*)malloc(sizeof(NODE));
	printf("Student %d\nenter Role number: \n",count++);
	scanf("%d",&nw->st_rec.role);
	puts("Enter name: ");
	scanf("%s",nw->st_rec.name);
	tail->next=nw;
	nw->prev=tail;
	tail=nw;
	tail->next=head;
	puts("");
}
void search()
{
	NODE *temp;
	int role;
	puts("\nEnter the role number: ");
	scanf("%d",&role);
	for(temp=head;temp->next!=head && temp->st_rec.role!=role;temp=temp->next)
    continue;
	if(temp->next!=head)
    {
        puts("Record found. It's between: ");
        disp_pn(temp);
    }
    else
    {
        puts("Record not found!");
        return;
    }
}
void delete_rec()
{
	NODE *temp;
	int role;
	if(head==NULL)
    {
        puts("No records!");
        return;
    }
	puts("Enter the role number: ");
	scanf("%d",&role);
	for(temp=head;temp->next!=head && temp->st_rec.role!=role;temp=temp->next)
	continue;
	disp_pn(temp);
	if(temp==tail)
    {
        tail=tail->prev;
        temp->prev=NULL;
        temp->next=NULL;
        tail->next=head;
        free(temp);
    }
    else if(temp==head)
    {
        head=head->next;
        head->prev=NULL;
        tail->next=head;
        temp->next=NULL;
        free(temp);
    }
    else
    {
        temp->prev->next=temp->next;
	//printf("%u",temp->prev);
        temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
        free(temp);
    }

}
int main()
{
	int n,choice;
	char choice2;
	puts("Enter the number of students: ");
	scanf("%d",&n);
	puts("\nEnter the records: \n");
	create_rec(n);
	do
	{
		puts("Enter your option:\n1. Add one more record\n2. Search for a record\n3. Delete a record\n4. exit");
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
		puts("\nContinue? Y or N?");
		fflush(stdin);
		scanf("%c",&choice2);
	}while(choice2=='Y'||choice2=='y');
	return 0;
}

