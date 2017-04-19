#include<stdio.h>
#include<stdlib.h>
typedef struct hash_table_element
{
	char *str;
	struct hash_table_element *next,*chain;
}hash_table;
hash_table *head,*tail,*nw;
int h(char *key,int m)
{
	//hash_table *temp;
	int i,sum=0;
	for(i=0;key[i]!='\0';i++)
	sum+=key[i]-97;
	return(sum%m);
}
void linear_probing(hash_table *temp,char *key)
{
	for(;1;temp=temp->next)
	{
		if(temp->str!='\0')
		continue;
		else
		{
			temp->str=key;
			return;
		}
	}
}
void chaining_hashing(hash_table *temp,char *key)
{
	if(temp->chain==NULL)
	{
		nw=(hash_table*)malloc(sizeof(hash_table));
		nw->str=key;
		nw->chain=NULL;
		nw->next=NULL;
		temp->chain=nw;
	}
	else
	{
		hash_table *temp2;
		for(temp2=temp;temp2->chain!=NULL;temp2=temp2->chain)
		continue;
		nw=(hash_table*)malloc(sizeof(hash_table));
		nw->str=key;
		nw->chain=NULL;
		nw->next=NULL;
		temp2->chain=nw;
	}
}
int main()
{
	char *keys[]={"best","true","hill","dove","van","good","egg","lap"};
	int i,j,m=11,y,choice;//m=number of available memory locations,y=output of the hashing function h(x)
	hash_table *temp;
	nw=(hash_table*)malloc(sizeof(hash_table));
	nw->str='\0';
	head=nw;
	tail=nw;
	tail->next=NULL;
	tail->chain=NULL;
	for(i=0;i<m-1;i++)
	{
		nw=(hash_table*)malloc(sizeof(hash_table));
		nw->str='\0';
		tail->next=nw;
		tail=nw;
		tail->next=NULL;
		tail->chain=NULL;
	}//all the s formed(hash_table_elements) together form the hash table
	for(i=0;i<8;i++)//for each string in the keys array
	{
		y=h(keys[i],m);
		for(j=0,temp=head;j<y;j++)
		temp=temp->next;
		if(temp->str=='\0')//if the yth node's string filed is empty
		temp->str=keys[i];
		else
		{
			puts("\nThe index position is full.");
			printf("'%s' collided with already existing string '%s'\n",keys[i],temp->str);
			puts("Choose your method to resolve collision:");
			puts("1. Linear Probing (Closed Hashing)");
			puts("2. Chaining (Open Hashing)");
			puts("3. Overwrite");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					linear_probing(temp,keys[i]);
					break;
				case 2:
					chaining_hashing(temp,keys[i]);
					break;
				case 3:
					temp->str=keys[i];
					break;
			}
		}
	}
	puts("The strings are:\n");
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->chain!=NULL)
		{
			hash_table *aux_temp;
			for(aux_temp=temp;aux_temp!=NULL;aux_temp=aux_temp->chain)
			printf("%s ",aux_temp->str);
			puts("");
		}
		else if(temp->str=='\0')
        puts("");
        else
		printf("%s\n",temp->str);
	}
}

