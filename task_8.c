/*variable descriptions:*/
/*main_head,main_tail and main_new are used to point to the nodes of the queue of trucks*/
/*later_head etc for retained trucks*/
/*next_head to keep track on the truck waiting outside the garage once one of the trucks enters the garage*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	unsigned int id;
	struct node *next;
}*main_nw,*main_head,*main_tail,*later_nw,*later_head,*later_tail,*next_head;
unsigned int flag=1,flag2=1;
void on_road(unsigned int t_id)
{
    main_nw=(struct node*)malloc(sizeof(struct node));
    main_nw->id=t_id;
    if(flag==1)
    {
        main_head=main_nw;
        main_tail=main_nw;
        next_head=main_nw;
        main_tail->next=main_head;//circular queue
        flag=0;
    }
    else
    {
        main_tail->next=main_nw;
        main_tail=main_nw;
        main_tail->next=main_head;
    }

}
void enter_garage(unsigned int t_id)
{
    if(t_id==main_head->id)
    {
        //struct node *temp;
        if(main_head!=main_tail)
        {
            printf("Train ID %d moved into garage.",main_head->id);
            next_head=main_head->next;
            main_head->next=NULL;
        }
        else
        {
            printf("Truck ID %d moved into the garage.",main_head->id);
            next_head=NULL;
            main_head->next=NULL;
            flag=1;
        }
    }
    else
        printf("Truck with ID %u cannot be moved!",t_id);
}
void exit_garage(unsigned int t_id)
{
    if(t_id==main_head->id)
    {
       if(main_head->next==NULL)
       {
           free(main_head);
           main_head=next_head;
       }
       else
        puts("Truck is still waiting to enter into the garage.");
    }
    else
        puts("The truck has long to go!");
}
void retain(unsigned int index)
{
    struct node *temp;
    int i;
    for(i=0,temp=main_head;i<(index-1);i++)
        temp=temp->next;
    later_nw=(struct node*)malloc(sizeof(struct node));
    later_nw->id=(temp->next)->id;
    temp->next=(temp->next)->next;
    if(flag2==1)
    {
        later_nw->next=NULL;
        flag2=0;
        later_head=later_nw;
        later_tail=later_nw;
    }
    else
    {
        later_tail->next=later_nw;
        later_tail=later_nw;
    }
}
void show_main()
{
    struct node *temp;
    if(next_head==NULL)
        puts("No trucks in the queue!");
    else
    {
    	puts("The trucks yet to be serviced are:");
        for(temp=next_head;temp!=main_tail;temp=temp->next)
        printf("%u\n",temp->id);
        printf("%u\n",temp->id);
    }
}
void show_later()
{
    struct node *temp;
    for(temp=later_head;temp!=later_tail;temp=temp->next)
        printf("The trucks retained are:\n%u\n",temp->id);
    printf("%u\n",temp->id);
}
int main()
{
	unsigned int choice,t_id,index;
	do
    {
        puts("Choose your option:\n1. New truck on road\n2. Enter garage\n3. Exit garage\n4. Retain a truck\n5. Show trucks yet to be serviced\n6. Show retained trucks");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                puts("Enter truck ID");
                scanf("%u",&t_id);
                on_road(t_id);
                break;
            case 2:
                if(main_tail==NULL)
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
                if(main_tail==NULL)
                {
                    puts("No trucks in the queue!\n");
                    break;
                }
                puts("Enter the truck number, n:");
                scanf("%u",&index);
                retain(index);
                break;
            case 5:
                if(main_tail==NULL)
                {
                    puts("No trucks in the queue!\n");
                    break;
                }
                show_main();
                break;
            case 6:
                if(main_tail==NULL)
                {
                    puts("No trucks retained!\n");
                    break;
                }
                show_later();
                break;
        }
    }while(choice<7);
    return 0;
}

