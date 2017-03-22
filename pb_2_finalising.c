#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*tail,*nw;
int flag=1,central_val,flag2=1,flag3=1,found_equal=0;
struct node *small_head,*small_tail,*large_head,*large_tail,*temp,*equal_head,*equal_tail;
void creation(int n)
{
	int item,i;
	puts("Enter data: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		nw=(struct node*)malloc(sizeof(struct node));
		nw->data=item;
		if(flag==1)
		{
			head=nw;
			tail=nw;
			tail->next=NULL;
			flag=0;
		}
		else
		{
			tail->next=nw;
			tail=nw;
			tail->next=NULL;
		}
	}
	flag=1;
}
void display()
{
	struct node *temp;
	puts("The linked list is: ");
	for(temp=head;temp!=tail;temp=temp->next)
	printf("%d->",temp->data);
	printf("%d\n\n",temp->data);
}
struct node* partition(struct node* address)
{
	if(address->data<central_val)
	{
		if(address->next==NULL)
		{
		    if(flag2==1)
            {
                small_head=address;
                flag2=0;
            }
			small_tail=address;
			return(address);
		}
		else
		{
		    if(flag2==1)
            {
                small_head=address;
                flag2=0;
            }
		    small_tail=address;
			address->next=partition(address->next);
			return(address);
		}
	}
	else if(address->data>central_val)
	{
		if(flag==1)
		{
			large_head=address;
			large_tail=large_head;
			//large_tail=NULL;
			flag=0;
			address=address->next;
			partition(address);
		}
		else
		{
			large_tail->next=address;
			large_tail=large_tail->next;
			//large_tail->next=NULL;
			if(address->next==NULL)
			return address;
			else
			{
				address=address->next;
				return(partition(address));
			}
		}
	}
	else if(address->data==central_val)
	{
		found_equal=1;
		if(flag3==1)
		{
			equal_head=address;
			equal_tail=equal_head;
			//large_tail=NULL;
			flag3=0;
			address=address->next;
			partition(address);
		}
		else
		{
			equal_tail->next=address;
			equal_tail=equal_tail->next;
			//large_tail->next=NULL;
			if(address->next==NULL)
			return address;
			else
			{
				address=address->next;
				return(partition(address));
			}
		}
	}
}
int main()
{
	int n;
	//struct node *temp1;
	puts("Enter the number of nodes:");
	scanf("%d",&n);
	creation(n);
	//temp=head;
	display();
	puts("Enter the central value: ");
	scanf("%d",&central_val);
	//for(temp1=head;temp1->data!=central_val;temp1=temp1->next)
	//continue;
	partition(head);
	if(found_equal==1)
	{
		small_tail->next=equal_head;
		equal_tail->next=large_head;
	}
	else
	small_tail=large_head;
	for(temp=small_head;temp!=large_tail;temp=temp->next)
        printf("%d->",temp->data);
        printf("%d\n",temp->data);
	return 0;
}

