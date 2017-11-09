#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node{
		int data;
		struct node *next;
};
typedef struct node N;
N *head=NULL;
void createLL()
{
    N *last, *temp, *start;
	int c;
	do{
		temp=(N*)malloc(sizeof(N));
		printf("Enter the data:");
		scanf("%d",&temp->data);
		temp->next=NULL;
		//printf("%d",temp->data);
		if(head==NULL)
		{
			head=last=start=temp;
		}
		else
		{
		last->next=temp;
		last=temp;	
		}
		printf("enter 1 to repeat:");
		scanf("%d",&c);
	}while(c==1);
	
	//temp=head;
}
	
	
	void show()
	{
	
	N *temp;
	temp=head;
	printf("The link list is:");
	while(temp!=NULL)
	{
		printf("%d=>",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	}	
	
void insert_beg()
{
	N *last, *temp, *new_node;
	new_node=(N*)malloc(sizeof(N));
	printf("Enter the data to insert\n");
	scanf("%d",&new_node->data);
	if(head==NULL)
	{
	head=new_node;
	new_node->next=NULL;
	}
	else
	{
	new_node->next=head;
	head=new_node;
	}
}

void insert_end()
{
	N *ptr, *new_node;
	new_node=(N*)malloc(sizeof(N));
	printf("Enter the data to insert at last\n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;	
	}
	ptr->next=new_node;
	
}

void insert_pos()
{
	N *ptr,*new_node,*preptr;
	int count=1,pos;
	new_node=(N*)malloc(sizeof(N));
	printf("Enter the data to insert at pos\n");
	scanf("%d",&new_node->data);
	
	printf("enter the position u want to enter:");
	scanf("%d",&pos);
	ptr=head;
	while(count!=pos)
	{
		preptr=ptr;
		ptr=ptr->next;
		count++;
	}
	new_node->next=ptr;
	preptr->next=new_node;
}

void del_beg()
{
	N *start;
	if(head==NULL)
	{
		printf("List empty\n");
	}
	else{
		printf("the deleted item is %d\n",head->data);
		start=head->next;
		head=start;
	}
}

void del_last()
{
	N *last, *temp=head, *ptr=head;;
	while(temp->next!=NULL)
	{
		ptr=temp;
		temp=temp->next;
	}
	printf("deleted item is %d\n",temp->data);
	ptr->next=NULL;
}

void del_pos()
{
	N *temp=head, *ptr=head;
	int c=1,pos;
	printf("Enter the position:");
	scanf("%d",&pos);
	while(c!=pos)
	{
		ptr=temp;
		temp=temp->next;
		c++;
	}
	printf("The deleted item is %d\n",temp->data);
	ptr->next=temp->next;
}


int main()
{
		int choice;
	do{
	printf("1.create\n2.insert at beginning\t3.insert at last\t4.insert at position\t5.del beginning\t6.del last\t7.del position\t8.display\t9.exit\tenter ur choice: ");
		scanf("%d",&choice);
		{
			switch(choice)
			{
			case 1:
				createLL();
				break;
			case 2:
				insert_beg();
				break;
			case 3:
				insert_end();
				break;
			case 4:
				insert_pos();
				break;
			case 5:
				del_beg();
				break;
			case 6:
				del_last();
				break;
			case 7:
				del_pos();
				break;
			case 8:
				show();
			case 9:
				exit(0);
			}
		}
	}while(choice!=9);
}

