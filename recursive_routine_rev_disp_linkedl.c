#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*tail,*nw;
void creation(int n)
{
	int i;
	puts("enter data: ");
	nw=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&nw->data);
	head=nw;
	tail=nw;
	for(i=0;i<n-1;i++)
	{
		nw=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&nw->data);
		tail->next=nw;
		tail=nw;
	}
}
void print_rev(struct node *temp)
{
	if(temp==tail)
	{
		printf("\n%d\n",temp->data);
		return;
	}
	print_rev(temp->next);
	printf("%d\n",temp->data);
	return;
}
int main()
{
	struct node *temp;
	int n;
	puts("enter the number of nodes: ");
	scanf("%d",&n);
	creation(n);
	temp=head;
	print_rev(temp);
}
