//mid is the end of first part of the divided linked list and mid_next is the head of the next part of the linked list.
typedef struct node NODE
NODE *find_mid(NODE *head,NODE *tail,NODE **mid_next)//standard routine to find the mid-node of a linked list!
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
	return(temp1)
}
