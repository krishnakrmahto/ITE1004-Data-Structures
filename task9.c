#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int reg;
	struct node *next,*prev;
}NODE;
NODE *nw1,*nw2,*head1,*head2,*tail1,*tail2,*head_final,*tail_final;
NODE *find_mid(NODE *head,NODE *tail)
{
	int count=1;
	NODE *temp1,*temp2;
	for(temp2=head;temp2!=NULL;temp2=temp2->next,(count%2==0)?(temp1=temp1->next):(temp2=temp2))
	continue;
	return temp1;
}
void merge(NODE *head,NODE *mid,NODE *mid_next,NODE *tail)
{
	NODE *temp1,*temp2,*temp3;
	if(head->reg>mid_next->reg)
	{
		head_final=mid_next;
		temp1=mid_next->next;
		temp2=head;
		head_final->prev=NULL;
	}
	else
	{
		head_final=head;
		temp2=head_final->next;
		temp1=mid_next;
		head_final->next=NULL;

	}
	for(temp3=head_final;temp1!=NULL||temp2!=NULL;)
	{
		if(temp1->reg>temp2->reg)
		{
			temp3->next=temp2;
			temp2->prev=temp3;
			temp2=temp2->next;
			temp3=temp3->next;
		}
		else
		{
			temp3->next=temp1;
			temp1->prev=temp3;
			temp1=temp1->next;
			temp3=temp3->next;
		}
	}
	if(temp1==NULL)
	{
		temp3->next=temp2;
		temp2->prev=temp3;
		tail_final=tail2;
	}
	else
	{
		temp3->next=temp1;
		temp1->prev=temp3;
		tail_final=tail1;
	}
}
void merge_sort(NODE *head,NODE *tail)
{
	NODE *mid;
	mid=find_mid(head,tail);
	merge_sort(head,mid);
	merge_sort(head,mid);
	merge(head,mid,mid->next,tail);
}
void creation1(int n1)
{
	int i;
	puts("enter data: ");
	nw1=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&nw1->reg);
	head1=nw1;
	tail1=nw1;
	head1->prev=NULL;
	tail1->next=NULL;
	for(i=0;i<n1-1;i++)
	{
		nw1=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&nw1->reg);
		tail1->next=nw1;
		nw1->prev=tail1;
		tail1=nw1;
		tail1->next=NULL;
	}
}
void creation2(int n2)
{
	int i;
	puts("enter data: ");
	nw2=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&nw2->reg);
	head2=nw2;
	tail2=nw2;
	head2->prev=NULL;
	tail2->next=NULL;
	for(i=0;i<n2-1;i++)
	{
		nw2=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&nw2->reg);
		tail2->next=nw2;
		nw2->prev=tail2;
		tail2=nw2;
		tail2->next=NULL;
	}
}
void final_merge(NODE *head1,NODE *tail1,NODE *head2,NODE *tail2)
{
	tail1->next=head2;
	head2->prev=tail1;
	//tail1=tail2;
	head_final=head1;
	tail_final=tail2;
}
void display_final_list(NODE *temp)
{
	puts("Resultant list of students: ");
	for(;temp!=NULL;temp=temp->next)
	printf("%d\n",temp->reg);
}
int main()
{
	int n1,n2,choice;
	puts("Enter the number of students for Set 1:");
	scanf("%d",&n1);
	creation1(n1);
	puts("Enter the number of students for Set 2: ");
	scanf("%d",&n2);
	creation2(n2);
	puts("Enter your choice:\n1. Simple merging\n2. Merge into a sorted list");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			final_merge(head1,tail1,head2,tail2);
			break;
		case 2:
			merge_sort(head1,tail1);
			merge_sort(head2,tail2);
			final_merge(head1,tail1,head2,tail2);
			break;
	}
	display_final_list(head_final);
	return 0;
}

