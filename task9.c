#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int reg;
    struct node* next;
}NODE;
NODE *head1,*head2,*tail1,*tail2,*head_final,*tail_final,*nw1,*nw2;
NODE* sortedmerge(NODE* a, NODE* b);
void find_mid(NODE* source, NODE** frontRef, NODE** backRef);
void mergesort(NODE** Ptr_To_head)//head is pointer to first node
{
    NODE* head = *Ptr_To_head; 
    NODE* a;
	NODE* b;
    if((head==NULL)||(head->next==NULL))
        return;
    find_mid(head, &a, &b);
    mergesort(&a);
    mergesort(&b);
    *Ptr_To_head = sortedmerge(a,b);
}
NODE* sortedmerge(NODE* a, NODE* b)
{
    NODE *result=NULL;
    if (a==NULL)
        return b;
    else if (b==NULL)
        return a;    
    if (a->reg<=b->reg)
    {
        result=a;
        result->next=sortedmerge(a->next,b);
    }
	else
    {
        result=b;
        result->next=sortedmerge(a,b->next);
    }
    return(result);
}    
void find_mid(NODE* source, NODE** frontRef, NODE** backRef)
{
    NODE* fast;
    NODE* slow;
    if (source==NULL || source->next==NULL)
    {
		*frontRef = source;
		*backRef = NULL;
	}
    else
    {
        for(slow=source,fast=source->next;fast!=NULL;)
        {
			fast=fast->next;
            if (fast!=NULL)
            {
            	slow=slow->next;
                fast=fast->next;
            }
        }
	*frontRef=source;
    *backRef=slow->next;
	slow->next=NULL;
    }
}
void final_merge(NODE *head1,NODE *tail1,NODE *head2,NODE *tail2)
{
	tail1->next=head2;
	head_final=head1;
	tail_final=tail2;
}
void printlist(NODE *node)
{
    for(;node!=NULL;node=node->next)
		printf("%d ",node->reg);
}     
void creation1(int n1)
{
	int i;
	printf("Enter registration numbers of %d students:\n ",n1);
	nw1=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&nw1->reg);
	head1=nw1;
	tail1=nw1;
	tail1->next=NULL;
	for(i=0;i<n1-1;i++)
	{
		nw1=(NODE*)malloc(sizeof(NODE));
		scanf("%d",&nw1->reg);
		tail1->next=nw1;
		tail1=nw1;
		tail1->next=NULL;
	}
}
void creation2(int n2)
{
	int i;
	printf("Enter registration numbers of %d students:\n ",n2);
	nw2=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&nw2->reg);
	head2=nw2;
	tail2=nw2;
	tail2->next=NULL;
	for(i=0;i<n2-1;i++)
	{
		nw2=(NODE*)malloc(sizeof(NODE));
		scanf("%d",&nw2->reg);
		tail2->next=nw2;
		tail2=nw2;
		tail2->next=NULL;
	}
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
			mergesort(&head1);
			mergesort(&head2);
			final_merge(head1,tail1,head2,tail2);
			mergesort(&head_final);
			break;
	}
	printlist(head_final);

    }
