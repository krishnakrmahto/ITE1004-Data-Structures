#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int reg;
	struct node *next;
}NODE;
NODE *nw1,*nw2,*head1,*head2,*tail1,*tail2;
int flag1=1,flag2=1;
void creation1(int n)
{
	int i;
	if(n!=0)
	printf("Enter the registration numbers of %d students:\n",n);
	for(i=0;i<n;i++)
	{
		nw1=(NODE*)malloc(sizeof(NODE));
		scanf("%d",&nw1->reg);
		if(flag1==1)
		{
			head1=nw1;
			tail1=nw1;
			tail1->next=NULL;
			flag1=0;
		}
		else
		{
			tail1->next=nw1;
			tail1=nw1;
			tail1->next=NULL;
		}
	}
}
void creation2(int n)
{
	int i;
	if(n!=0)
	printf("Enter the registration numbers of %d students:\n",n);
	for(i=0;i<n;i++)
	{
		nw2=(NODE*)malloc(sizeof(NODE));
		scanf("%d",&nw2->reg);
		if(flag2==1)
		{
			head2=nw2;
			tail2=nw2;
			tail2->next=NULL;
			flag2=0;
		}
		else
		{
			tail2->next=nw2;
			tail2=nw2;
			tail2->next=NULL;
		}
	}
}
void find_mid(NODE *head,NODE **a,NODE **b)
{
	NODE *slow,*fast;
	for(slow=head,fast=head->next;fast!=NULL;)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	*a=head;
	*b=slow->next;
	slow->next=NULL;
}
NODE *merge(NODE **head1_ptr,NODE **head2_ptr)
{
	if(*head1_ptr==NULL)
	return *head2_ptr;
	else if(*head2_ptr==NULL)
	return *head1_ptr;
	if((*head1_ptr)->reg<=(*head2_ptr)->reg)
	{
		(*head1_ptr)->next=merge(&((*head1_ptr)->next),head2_ptr);
		return(*head1_ptr);
	}
	else
	{
		(*head2_ptr)->next=merge(head1_ptr,&((*head2_ptr)->next));
		return(*head2_ptr);
	}
}
void merge_sort(NODE **Ptr_to_head)
{
	NODE *first_head,*second_head;
	if(*Ptr_to_head!=NULL && (*Ptr_to_head)->next!=NULL)
	{
		find_mid(*Ptr_to_head,&first_head,&second_head);
		merge_sort(&first_head);
		merge_sort(&second_head);
		*Ptr_to_head=merge(&first_head,&second_head);
	}
}
void final_merge(NODE *temp1,NODE* temp2)
{
	/*if(temp1==NULL)
	return;
	if(temp2=NULL)
	return;*/
	for(;temp1->next!=NULL;temp1=temp1->next)
	continue;
	tail1=temp1;
	tail1->next=temp2;
}
void printlist(NODE *temp)
{
	puts("Required list");
	for(;temp!=NULL;temp=temp->next)
	printf(" %d ",temp->reg);
	puts("");
}
int main()
{
	head1=head2=tail1=tail2=nw1=nw2=NULL;
	int n1,n2,choice1;
	char choice2;
	puts("Enter the number of students for SET A: ");
	scanf("%d",&n1);
	creation1(n1);
	printlist(head1);
	puts("Enter the number of students for SET B: ");
	scanf("%d",&n2);
	creation2(n2);
	//printlist(head2);
	puts("Enter your choice");
	puts("1. Simple merging");
	puts("2. Merge into a sorted list");
	scanf("%d",&choice1);
	switch(choice1)
	{
		case 1:
			final_merge(head1,head2);
			break;
		case 2:
			merge_sort(&head1);
			//printlist(head1);
			merge_sort(&head2);

			final_merge(head1,head2);
			merge_sort(&head1);
			break;
	}
	printlist(head1);
}

