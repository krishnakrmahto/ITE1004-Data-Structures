#include<stdio.h>
struct node
{
	int data;
	struct node *next;
}*nw,*head,*tail;
void creation()
{
	int n,item,i;
	puts("Enter the number of nodes: ");
	scanf("%d",&n);
	puts("Enter the values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",item);
		if(nw->data==NULL)
		nw->data=item;
		else
		{
			nw=(struct node*)malloc(sizeof(struct node));
			nw->data=item;
			nw->next=NULL;
			tail->next=nw;
			tail=nw;
		}
	}
}
void main()
{
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data=NULL;
	nw->next=NULL;
	head=nw;
	tail=nw;
	creation();
}
