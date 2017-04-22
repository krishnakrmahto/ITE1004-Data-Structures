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
	return nw;
}
PDT *insertion(PDT *root,int insert_code)
{
	PDT *parent;
	create_node();//a node pointed by nw global variable is create
	nw->code=insert_code;
	puts("Enter name of the product: ");
	scanf("%s",nw->name);
	puts("Enter price of the product:");
	scanf("%d",&nw->price);
	puts("Enter quantity: ");
	scanf("%d",&nw->qty);
	puts("Enter receiving date- dd mm yyyy: ");
	scanf("%d%d%d",&nw->rcv_date.day,&nw->rcv_date.month,&nw->rcv_date.year);
	puts("Enter expiry date- dd mm yyyy: ");
	scanf("%d%d%d",&nw->exp_date.day,&nw->exp_date.month,&nw->exp_date.year);
	if(root==NULL)
	root=nw;
	else
	{
		for(parent=root;parent!=NULL;)
		{
			if(nw->code>parent->code)
			{
				if(parent->right==NULL)
				{
					parent->right=nw;
					return;//or break the loop
				}
				parent=parent->right;
			}
			else if(nw->code<parent->code)
			{
				if(parent->left==NULL)
				{
					parent->left=nw;
					return;
				}
				parent=parent->left;
			}
			else
			{
				puts("Product already exists!");
				return nw;
			}
		}	
	}
	return nw;	
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
	puts("2. Update price");
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
		printf("Code: %20d",root->code);
		printf("Name: %20s",root->name);
		printf("Price: %20d",root->price);
		printf("Quantity: %20d",root->qty);
		printf("Receive Date: %20d",root->rcv_date);
		printf("Expiry Date: %20d",root->exp_date);
		puts("");
		inorder(root->right);
	}
}
void preorder(PDT *root)
{
	if(root!=NULL)
	{
		printf("Code: %20d",root->code);
		printf("Name: %20s",root->name);
		printf("Price: %20d",root->price);
		printf("Quantity: %20d",root->qty);
		printf("Receive Date: %20d",root->rcv_date);
		printf("Expiry Date: %20d",root->exp_date);
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
		printf("Code: %20d",root->code);
		printf("Name: %20s",root->name);
		printf("Price: %20d",root->price);
		printf("Quantity: %20d",root->qty);
		printf("Receive Date: %20d",root->rcv_date);
		printf("Expiry Date: %20d",root->exp_date);
		puts("");
	}
}
void out_of_stock(PDT *root)
{
	puts("Out of stock (Quantity=0) products are: ");
	if(root!=NULL)
	{
		inorder(root->left);
		if(root->qty==0)
		{
			printf("Code: %20d",root->code);
			printf("Name: %20s",root->name);
			printf("Price: %20d",root->price);
			printf("Receive Date: %20d",root->rcv_date);
			printf("Expiry Date: %20d",root->exp_date);
			puts("");
		}
		inorder(root->right);
	}
}
void in_stock(PDT *root)
{
	puts("In-stock products: ");
	if(root!=NULL)
	{
		inorder(root->left);
		if(root->qty!=0)
		{
			printf("Code: %20d",root->code);
			printf("Name: %20s",root->name);
			printf("Price: %20d",root->price);
			printf("Quantity: %20d",root->qty);
			printf("Receive Date: %20d",root->rcv_date);
			printf("Expiry Date: %20d",root->exp_date);
			puts("");
		}
		inorder(root->right);
	}
}
int main()
{
	root=NULL;
	nw=NULL;
	int choice,new_code,existing_code;
	do
	{
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
				insertion(root,new_code);
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
				deletion(root,existing_code);
				break;
			case 8:
				exit(0);
				break;
			case 7:
				out_of_stock(root);
				in_stock(root);
				break;
			}
		}while(choice<9);
	return 0;
}
