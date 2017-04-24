#include<stdio.h>
#include<stdlib.h>
typedef struct date
{
	int day,month,year;
}DATE;
typedef struct node
{
	struct node *left,*right;
	int code;
	char *name;
	int price;
	int qty;
	DATE rcv_date,exp_date;
}PDT;
PDT *nw,*root;
PDT *create_node()
{
	nw=(PDT*)malloc(sizeof(PDT));
	nw->left=NULL;
	nw->right=NULL;
	nw->name=(char*)malloc(sizeof(char*));
	return nw;
}
PDT *insertion(PDT **root_add,int insert_code)
{
	PDT **parent_add;
	create_node();//a node pointed by nw global variable is create
	nw->code=insert_code;
	puts("Enter name of the product: ");
	scanf("%s",nw->name);
	puts("Enter price of the product (Rs):");
	scanf("%d",&nw->price);
	puts("Enter quantity: ");
	scanf("%d",&nw->qty);
	puts("Enter receiving date- dd mm yyyy: ");
	scanf("%d%d%d",&nw->rcv_date.day,&nw->rcv_date.month,&nw->rcv_date.year);
	puts("Enter expiry date- dd mm yyyy: ");
	scanf("%d%d%d",&nw->exp_date.day,&nw->exp_date.month,&nw->exp_date.year);
	if(root==NULL)
	root=nw;//global root is assigned its value
	else
	{
		for(parent_add=root_add;*parent_add!=NULL;)
		{
			if(nw->code>(*parent_add)->code)
			{
				if((*parent_add)->right==NULL)
				{
					(*parent_add)->right=nw;
					return;//or break the loop
				}
				parent_add=&((*parent_add)->right);
			}
			else if(nw->code<(*parent_add)->code)
			{
				if((*parent_add)->left==NULL)
				{
					(*parent_add)->left=nw;
					return;
				}
				parent_add=&((*parent_add)->left);
			}
		}
	}
}
PDT *find(PDT *root,int search_code)
{
	if(root==NULL)
	return NULL;
	if(search_code<root->code)
	return(find(root->left,search_code));
	if(search_code>root->code)
	return(find(root->right,search_code));

	return root;//reaching this line means the searh item has been found.
}
void update(PDT *node)
{
	if(node==NULL)
	{
		puts("Product not found!");
		return;
	}
	int choice;
	printf("Product code: %d\n",node->code);
	puts("Choose your option: ");
	puts("1. Update name");
	puts("2. Update price (Rs)");
	puts("3. Update quantity in stock");
	puts("4. Update receiving date");
	puts("5. Update expiry date");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			puts("Enter new name:");
			scanf("%s",node->name);
			break;
		case 2:
			puts("Enter new price");
			scanf("%d",&node->price);
			break;
		case 3:
			puts("Enter quantity:");
			scanf("%d",&node->qty);
			break;
		case 4:
			puts("Enter receiving date");
			scanf("%d%d%d",&node->rcv_date.day,&node->rcv_date.month,&node->rcv_date.year);
			break;
		case 5:
			puts("Enter expiry date:");
			scanf("%d%d%d",&node->exp_date.day,&node->exp_date.month,&node->exp_date.year);
			break;
	}
}
void inorder(PDT *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%-14s%-20d\n","Code: ",root->code);
		printf("%-14s%-20s\n","Name: ",root->name);
		printf("%-14s%-20d\n","Price(Rs): ",root->price);
		printf("%-14s%-20d\n","Quantity: ",root->qty);
		printf("%-14s%-2d-%d-%d\n","Receive Date: ",root->rcv_date.day,root->rcv_date.month,root->rcv_date.year);
		printf("%-14s%-2d-%d-%d\n","Expiry Date: ",root->exp_date.day,root->exp_date.month,root->exp_date.year);
		puts("");
		inorder(root->right);
	}
}
void preorder(PDT *root)
{
	if(root!=NULL)
	{
		printf("%-14s%-20d\n","Code: ",root->code);
		printf("%-14s%-20s\n","Name: ",root->name);
		printf("%-14s%-20d\n","Price(Rs): ",root->price);
		printf("%-14s%-20d\n","Quantity: ",root->qty);
		printf("%-14s%-2d%d%d\n","Receive Date: ",root->rcv_date.day,root->rcv_date.month,root->rcv_date.year);
		printf("%-14s%-2d-%d-%d\n","Expiry Date: ",root->exp_date.day,root->exp_date.month,root->exp_date.year);
		puts("");
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(PDT *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%-14s%-20d\n","Code: ",root->code);
		printf("%-14s%-20s\n","Name: ",root->name);
		printf("%-14s%-20d\n","Price(Rs): ",root->price);
		printf("%-14s%-20d\n","Quantity: ",root->qty);
		printf("%%-14s%-2d-%d-%d\n","Receive Date: ",root->rcv_date.day,root->rcv_date.month,root->rcv_date.year);
		printf("%-14s%-2d-%d-%d\n","Expiry Date: ",root->exp_date.day,root->exp_date.month,root->exp_date.year);
		puts("");
	}
}
void out_of_stock(PDT *root)
{
	if(root!=NULL)
	{
		out_of_stock(root->left);
		if(root->qty==0)
		{
            printf("%-14s%-20d\n","Code: ",root->code);
            printf("%-14s%-20s\n","Name: ",root->name);
            printf("%-14s%-20d\n","Price(Rs): ",root->price);
            printf("%-14s%-20d-%d-%d\n","Quantity: ",root->qty);
            printf("%-14s%-2d-%d-%d\n","Receive Date: ",root->rcv_date.day,root->rcv_date.month,root->rcv_date.year);
            printf("%-14s%-2d-%d-%d\n","Expiry Date: ",root->exp_date.day,root->exp_date.day,root->exp_date.year);
            puts("");
		}
		out_of_stock(root->right);
	}
}
void in_stock(PDT *root)
{
	
	if(root!=NULL)
	{
		in_stock(root->left);
		if(root->qty!=0)
		{
            printf("%-14s%-20d\n","Code: ",root->code);
            printf("%-14s%-20s\n","Name: ",root->name);
            printf("%-14s%-20d\n","Price(Rs): ",root->price);
            printf("%-14s%-20d\n","Quantity: ",root->qty);
            printf("%-14s%-2d-%d-%d\n","Receive Date: ",root->rcv_date.day,root->rcv_date.month,root->rcv_date.year);
            printf("%-14s%-2d-%d-%d\n","Expiry Date: ",root->exp_date.day,root->exp_date.month,root->exp_date.year);
            puts("");
		}
		in_stock(root->right);
	}
}
PDT *find_min(PDT* root)
{
	if(root->left==NULL)
	return root;
	find_min(root->left);
}
PDT *deletion(PDT **root_add,int del_item)
{
	if(del_item<(*root_add)->code)
	(*root_add)->left=deletion(&((*root_add)->left),del_item);
	else if(del_item>(*root_add)->code)
	(*root_add)->right=deletion(&((*root_add)->right),del_item);
	else//Reaching here means the del_item has been found in the tree
	{
		if((*root_add)->left==NULL&&(*root_add)->right==NULL)
		{
			*root_add=NULL;
			return *root_add;
		}
		else if((*root_add)->left==NULL)
		{
			*root_add=(*root_add)->right;
			return *root_add;
		}
		else if((*root_add)->right==NULL)
		{
			*root_add=(*root_add)->left;
			return root;
		}
		else
		{
			PDT *temp=find_min((*root_add)->right);
			(*root_add)->code=temp->code;
			(*root_add)->exp_date=temp->exp_date;
			(*root_add)->left=temp->left;
			(*root_add)->name=temp->name;
			(*root_add)->price=temp->price;
			(*root_add)->qty=temp->qty;
			(*root_add)->rcv_date=temp->rcv_date;
			(*root_add)->right=deletion(&((*root_add)->right),temp->code);
		}
	}
}
int main()
{
	root=NULL;
	nw=NULL;
	int choice,new_code,existing_code;
	do
	{
		puts("\nChoose your option");
		puts("1. Insert a new product");
		puts("2. Update information");
		puts("3. List products in ascending order (in-order)");
		puts("4. List in Pre-order");
		puts("5. List in Post-order");
		puts("6. Delete");
		puts("7. List out-of-stock first");
		puts("8. Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				puts("Enter unique code for new product: ");
				scanf("%d",&new_code);
				insertion(&root,new_code);
				break;
			case 2:
				puts("Enter unique code of existing product:");
				scanf("%d",&existing_code);
				update(find(root,existing_code));
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				puts("Enter unique code: ");
				scanf("%d",&existing_code);
				deletion(&root,existing_code);
				puts("Deletion completed.");
				break;
			case 8:
				exit(0);
				break;
			case 7:
				puts("Out of stock (Quantity=0) products are: ");
				out_of_stock(root);
				puts("In-stock products: ");
				in_stock(root);
				break;
			}
		}while(choice<9);
	return 0;
}

