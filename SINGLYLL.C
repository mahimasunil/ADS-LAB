#include<stdio.h>
#include<conio.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *top=NULL;
int count=0;
struct Node *temp;
void display()
{
	struct Node *temp=top;
	if(count==0)
	{
		printf("\nStack is Empty!!!\n");
		return;
	}
	else
	{
		printf("\nThere are currently %d items:\n",count);
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("End\n");
	}
}
void push(int el)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("Memory Allocation Failed\n");
		return;
	}
	temp->data=el;
	temp->next=top;
	top=temp;
	count++;
	display();
}
void pop()
{
	if(count==0)
	{
		printf("\nStack is Empty\n");
		return;
	}
	temp=top;
	top=top->next;
	printf("\nItem to be removed is %d\n",temp->data);
	free(temp);
	count--;
	display();
}
void search()
{
	int item,flag=0,position=1;
	printf("\nEnter search element:");
	scanf("%d",&item);
	if(top==NULL)
	{
		printf("\nStack Underflow\n");
		return;
	}
	temp=top;
	while(temp!=NULL)
	{
		if(temp->data==item)
		{
			flag=1;
			printf("\nElement %d found at position %d\n",item,position);
			break;
		}
		else
		{
			temp=temp->next;
			position++;
		}
	}
	if(flag==0)
	{
		printf("\nElement %d is not found\n",item);
	}
}
void main()
{
	int choice,element;
	clrscr();
	while(1)
	{
		printf("\nStack Operations:\n");
		printf("1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter Element to push:");
				scanf("%d",&element);
				push(element);
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: search();
				break;
			case 5:exit(0);
			default: printf("Invalid choice!Please try Again.\n");
		}
	}
	getch();
}