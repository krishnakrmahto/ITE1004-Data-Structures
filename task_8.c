/*variable descriptions:*/
/*main_head,main_tail and main_new are used to point to the nodes of the queue of trucks*/
/*later_head etc for retained trucks*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	unsigned int id;
	struct node *next;
}*main_nw,*main_head,*main_tail,*garage_nw,*garage_head,*garage_tail,*later_nw,*later_head,*later_tail,*garage_head,*garage_tail,*garage_nw;
unsigned int flag=1,flag2=1,flag3=1,num_services=0,count_onroad=0;
void on_road(unsigned int t_id)
{
	count_onroad++;
    main_nw=(struct node*)malloc(sizeof(struct node));
    main_nw->id=t_id;
    if(flag==1)
    {
        main_head=main_nw;
        main_tail=main_nw;
        main_tail->next=main_head;//circular queue
        flag=0;
    }
    else
    {
        main_tail->next=main_nw;
        main_tail=main_nw;
        main_tail->next=main_head;
    }
    printf("Truck ID %d has been added to the queue.\n\n",t_id);
}
void enter_garage(unsigned int t_id)
{
    if(t_id==(main_head->id))
    {
    	main_head=main_head->next;
    	main_tail->next=main_head;
    	garage_nw=(struct node*)malloc(sizeof(struct node));
    	garage_nw->id=t_id;
    	if(flag3==1)
    	{
    		garage_head=garage_nw;
    		garage_tail=garage_nw;
    		flag3=0;
		}
		else
		{
			garage_tail->next=garage_nw;
			garage_tail=garage_nw;
		}
		printf("Truck ID %d has entered into the garage.\n\n",t_id);
	}
	else
	printf("Only truck ID %u can be moved.\n\n",main_head->id);
}
void exit_garage(unsigned int t_id)
{
	
    struct node *temp;
    if(t_id==garage_head->id)
    {
    	if(garage_head==garage_tail)
    	{
    		//garage_head->id=NULL;
    		garage_tail=NULL;
    		printf("The truck with ID %d has left the garage.\n\n",t_id);
    		flag3=1;
		}
    	
    	else
    	{
    		temp=garage_head;
			garage_head=garage_head->next;
			temp->next=NULL;
			printf("Truck ID %u has left the garage.\n\n",temp->id);
			num_services++;
			free(temp);
		}
	}
	else
	printf("Only truck ID %u can exit.\n\n",garage_head->id);
}
void retain(unsigned int index)
{
    struct node *temp;
    int i;
    if(index==1)
    {
    	temp=main_head;
    	//if(next_head==main_head)//if not it only means that the main_head is inside the garage
    	main_head=main_head->next;
    	//next_head=next_head->next;
    	temp->next=NULL;
    	later_nw=(struct node*)malloc(sizeof(struct node));
    	later_nw->id=temp->id;
    	if(flag2==1)
    	{
    		later_head=later_nw;
    		later_tail=later_nw;
    		flag2=0;
		}
		else
		{
			later_tail->next=later_nw;
			later_tail=later_nw;
		}
    	printf("Truck ID at index %u with ID %u has been retained for servicing later.\n",index,temp->id);
    	//free(temp->next);
	}
	else if(index<=count_onroad)
	{
    	for(i=0,temp=main_head;i<(index-2);i++)
        	temp=temp->next;
    	later_nw=(struct node*)malloc(sizeof(struct node));
    	later_nw->id=(temp->next)->id;
    	//free(temp->next);
    	temp->next=(temp->next)->next;
    	if(flag2==1)
    	{
    	    later_head=later_nw;
        	later_tail=later_nw;
        	flag2=0;
    	}
    	else
    	{
	        later_tail->next=later_nw;
    	    later_tail=later_nw;
    	}
    	//free(temp->next);
    	printf("Truck ID at index %d with ID %d has been retained for servicing later.\n",index,later_tail->id);
	}
	else
	puts("Index is greater than the number of trucks!");
	puts("");
}
void show_garage()
{
	struct node *temp;
	if(garage_tail==NULL)
	{
		puts("Garage is empty.");
		return;
	}
	else
	{
		puts("Trucks in the garage are IDs:");
		for(temp=garage_head;temp!=garage_tail;temp=temp->next)
		printf("%u\n",temp->id);
		printf("%u\n\n",temp->id);
	}
}
void show_main()
{
    struct node *temp;
    if(main_head==NULL)
        puts("No trucks in the queue!\n");
    else
    {
    	puts("The trucks yet to be serviced are IDs:");
        for(temp=main_head;temp!=main_tail;temp=temp->next)
        printf("%u\n",temp->id);
        printf("%u\n\n",temp->id);
    }
}
void show_later()
{
    struct node *temp;
    if(later_tail==NULL)
    {
    	puts("No trucks retained!\n");
    	return;
	}
    else if(later_head==later_tail)
    {
        printf("There is only one truck retained with ID %d\n\n",later_tail->id);
        return;
    }
    for(temp=later_head;temp!=later_tail;temp=temp->next)
        printf("The trucks retained are IDs:\n%u\n",temp->id);
    printf("%u\n\n",temp->id);
}
int main()
{
	unsigned int choice,t_id,index;
	do
    {
        printf("Choose your option:\n1. New truck on road\n2. Enter garage\n3. Exit garage\n4. Retain a truck\n5. Show garage\n6. Show trucks yet to be serviced\n7. Show retained trucks\nTotal number of services done= %u\n",num_services);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                puts("Enter truck ID:");
                scanf("%u",&t_id);
                on_road(t_id);
                break;
            case 2:
                if(main_head==NULL)
                {
                    puts("No trucks in the queue!\n");
                    break;
                }
                puts("Enter the truck ID:");
                scanf("%u",&t_id);
                enter_garage(t_id);
                break;
            case 3:
                 if(main_head==NULL)//because after the truck is entered into the garage head pointer is being kept attached to it until exit
                {
                    puts("No trucks in the garage!\n");
                    break;
                }
                puts("Enter the truck ID:");
                scanf("%u",&t_id);
                exit_garage(t_id);
                break;
            case 4:
                if(count_onroad==0)
                {
                    puts("No trucks in the queue!\n");
                    break;
                }
                puts("Enter the truck index, n:");
                scanf("%u",&index);
                retain(index);
                break;
            case 6:
                show_main();
                break;
            case 7:
                show_later();
                break;
        	case 5:
        		show_garage();
        		break;
        		
        }
    }while(choice<8);
    return 0;
}
