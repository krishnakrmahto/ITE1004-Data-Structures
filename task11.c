#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char alpha;
	struct node *next;
}FLAMES_NODE;
FLAMES_NODE *head,*tail,*nw;
int matching_chars(char *name1,char *name2)
{
	int count;
	for(;name1!='\0';name1++)
	for(;name2!='\0';name2++)
	{
		if(*name1==*name2);
		count++;
	}
	return(count);
}
void delete_char(FLAMES_NODE* del)
{
	FLAMES_NODE *temp;
	if(del==head)
	{
		head=head->next;
		del->next=NULL;
		free(del);
	}
	else if(del==tail)
	{
		for(temp=head;temp->next!=tail;temp=temp->next)
		continue;
		tail=temp;
		temp=temp->next;
		tail->next=NULL;
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
char play(n)
{
	FLAMES_NODE *temp;
	int i;
	if(n!=1)
	{
		for(i=0;i<n;i++)
		temp=temp->next;
		delete_char(temp);
		play(n);
	}
	return;
}
int main()
{
	int i,choice,match_num;
	char flames[]="FLAMES",*name1,*name2;
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
		tail->next=NULL;
	}
	puts("enter the two names: ");
	scanf("%s",name1);
	scanf("%s",name2);
	match_num=matching_chars(name1,name2);
	play(match_num);
	printf("The leter let is: %c\n",head->alpha);
	return 0;
}
