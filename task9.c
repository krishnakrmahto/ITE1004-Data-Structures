#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int reg;
	struct node *next;
}NODE;
NODE *nw1,*nw2,*head1,*head2,*tail1,*tail2,*head_final,*tail_final;
NODE *find_mid(NODE *head,NODE *tail,NODE** mid_next)//standard routine to find the mid-node of a linked list!
{
	int count=1;
	NODE *temp1,*temp2;
	for(temp1=head,temp2=head->next;temp2!=NULL;)
	{
		temp2=temp2->next;
		if(temp2!=NULL)
		{
			temp2=temp2->next;
			temp1=temp1->next;
		}
	}
	*mid_next=temp1->next;
	temp1->next=NULL;
	return(temp1);
}
NODE *merge(NODE *head,NODE *mid,NODE *mid_next,NODE *tail)
{
	NODE *head_curr;
	if(head==NULL)
	return mid_next;
	else
	return head;
	if(head->reg<=mid_next->reg)
	{
		head_curr=head;
		head_curr->next=merge(head->next,mid,mid_next,tail);
	}
	else
	{
		head_curr=mid_next;
		head_curr->next=merge(head,mid,mid_next->next,tail);
	}
	return head_curr;
}
void merge_sort(NODE *head,NODE *tail)
{
	if(head!=tail)
	{
		NODE *mid,**mid_next=(NODE*)malloc(sizeof(NODE));
		mid=find_mid(head,tail,mid_next);
		merge_sort(head,mid);
		merge_sort(mid_next,tail);
		head_final=merge(head,mid,mid_next,tail);//in the end of all the recursions, head_final will point to the first element
	}
}
void creation1(int n1)
{
	int i;
	puts("enter data: ");
	nw1=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&nw1->reg);
	head1=nw1;
	tail1=nw1;
	tail1->next=NULL;
	for(i=0;i<n1-1;i++)
	{
		nw1=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&nw1->reg);
		tail1->next=nw1;
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
	tail2->next=NULL;
	for(i=0;i<n2-1;i++)
	{
		nw2=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&nw2->reg);
		tail2->next=nw2;
		tail2=nw2;
		tail2->next=NULL;
	}
}
void final_merge(NODE *head1,NODE *tail1,NODE *head2,NODE *tail2)
{
	tail1->next=head2;
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

