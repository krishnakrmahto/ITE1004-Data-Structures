#include<stdio.h>
typedef struct record
{
	char *names;
	int roll;
}RECORD;
typedef struct node 
{
	RECORD  st_rec;
	struct node *prev,*next;
}NODE;
NODE *head,*tail,*nw;
void create_rec(int n)
{
	int i,count=1;
	nw=(NODE*)malloc(sizeof(NODE));
	printf("Student %d\nenter roll number: ",count++);
	scanf("%d",&nw->st_rec.roll);
	puts("enter name: ");
	scanf("%s",nw->st_rec.names);
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
		scanf("%s",nw->st_rec.names);
		tail->next=nw;
		nw->prev=tail;
		tail=nw;
		tail->next=NULL;
		puts("");
	}
}
void disp_pn(NODE *address)
{
	printf("Previous record: %d- %s\n",address->prev->st_rec.roll,address->prev->st_rec.names);
	printf("Next record: %d- %s\n\n",address->next->st_rec.roll,address->next->st_rec.names);
}
void search()
{
	NODE *temp;
	int roll;
	puts("enter the roll number: ");
	scanf("%d",&roll);
	for(temp=head;temp->st_rec.roll!=roll;temp=temp->next)
	continue;
	puts("Record found. It's between: ");
	disp_pn(temp);
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
	temp->prev=NULL;
	temp->next=NULL;
	free(temp);
}
int main()
{
	int n,choice;
	puts("enter the number of students: ");
	scanf("%d",&n);
	puts("Enter the records: ");
	create_rec(n);
	puts("enter your option:\n1. Add one more record\n2. Search for a record\n3. Delete a record");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			create_rec(1);
			break;
		case 2:
			search();
			break;
		case 3:
			delete_rec();
			break;
	}
}
