#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char alpha;
	struct node *next;
}FLAMES_NODE;
FLAMES_NODE *head,*tail,*nw;
int unmatching_chars(char *name1,char *name2)
{
    char *temp;
	int count=0,unmatched=0;
	for(;*name1!='\0';name1++)
	{
		for(temp=name2;*temp!='\0';temp++)
		{
			if(*name1==*temp)
			break;
			count++;
		}
		if(count==strlen(name2))
		unmatched++;
		count=0;
	}
	return(unmatched);
}
void delete_char(FLAMES_NODE* del)
{
	FLAMES_NODE *temp;
	if(del==head)
	{
		head=head->next;
		tail->next=head;
		del->next=NULL;
		free(del);
	}
	else if(del==tail)
	{
		for(temp=head;temp->next!=tail;temp=temp->next)
		continue;
		tail=temp;
		temp=temp->next;
		tail->next=head;
		free(temp);
	}
	else
	{
		for(temp=head;temp->next!=del;temp=temp->next)
		continue;
		temp->next=del->next;
		del->next=NULL;
		free(del);
	}
}
char play(int n,FLAMES_NODE *start)
{
    FLAMES_NODE *next_start;
	FLAMES_NODE *temp=start;
	int i;
	if(head!=tail)
	{
		for(i=0;i<n-1;i++)
		temp=temp->next;
		delete_char(temp);
	}
	return;
}
int main()
{
	FLAMES_NODE *temp;
	int i,choice,unmatch_num;
	char flames[]="FLAMES",name[2][30];
	nw=(FLAMES_NODE*)malloc(sizeof(FLAMES_NODE));
	nw->alpha=flames[0];
	head=nw;
	tail=nw;
	tail->next=NULL;
	for(i=1;i<6;i++)
	{
		nw=(FLAMES_NODE*)malloc(sizeof(FLAMES_NODE));
		nw->alpha=flames[i];
		tail->next=nw;
		tail=nw;
		tail->next=head;
	}
	puts("enter the two names: ");
	scanf("%s",name[0]);
	scanf("%s",name[1]);
	unmatch_num=unmatching_chars(name[0],name[1]);
	unmatch_num+=unmatching_chars(name[1],name[0]);
	play(unmatch_num,head);
	puts("Remaining nodes: ");
	for(temp=head;temp->next!=head;temp=temp->next)
	printf("\n%c\n",temp->alpha);
	printf("\n%c\n",temp->alpha);
	return 0;
}

