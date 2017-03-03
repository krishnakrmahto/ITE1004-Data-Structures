/*Algorithm:
1. Create two struct node type of temp1 and temp2 pointers.
2. temp1=head and temp2=tail.
3. while(temp1->next!temp2) do temp1=temp1->next
4. Now temp1 and temp2 are placed adjacent to each other. Print temp2->data and then do temp2=temp1.
5. Reset temp1=head.
6. Repeat 3,4,5 until temp2!=head.
7. When temp2==head, print temp2->data.
*/


#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*nw,*head,*tail;
void reverse_display()
{
	struct node *temp1,*temp2;
	for(temp2=tail;temp2!=head;temp2=temp1)
	{
		for(temp1=head;temp1->next!=temp2;temp1=temp1->next)
		continue;
		printf("%d\n",temp2->data);
		//temp2=temp1;
	}
	printf("%d",temp2->data);
}
void display()
{
	struct node *temp;
	//temp=head;
	//printf("%d\n",temp->data);
	for(temp=head;temp->next!=NULL;temp=temp->next)
	printf("%d\n",temp->data);
	printf("%d\n",temp->data);
}
void creation()
{
	int n,item,i;
	puts("Enter the number of nodes: ");
	scanf("%d",&n);
	puts("Enter the values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
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
	display();
	reverse_display();
}

