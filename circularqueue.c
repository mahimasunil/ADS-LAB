#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int front=-1,rear=-1,i;
int queue[MAX_SIZE];
int isEmpty()
{
return(front==-1&&rear==-1);
}
int isFull()
{
return((rear+1)%MAX_SIZE==front);
}
void enqueue(int data)
{
if(isFull())
{
printf("queueis full-overflow.cannot enqueue\n");
return ;
}
if(isEmpty())
{
front=rear=0;
}
else
{
rear=(rear+1)%MAX_SIZE;
}
queue[rear]=data;
printf("%d added to queue\n",data);
}
void dequeue()
{
if( isEmpty())
{
printf("queue is empty- underflow. cannot dequeue\n");
return ;
}
printf("%d removed from queue\n",queue[front]);
if(front==rear)
{
front=rear=-1;
}
else
{
front=(front+1)%MAX_SIZE;
}
}
int search(int key)
{
if(isEmpty())
{
printf("queue is empty.cannot search\n");
return -1;
}
i=front;
do
{
if(queue[i]==key)
{
printf("%d fount at position %din queue\n",key,i);
return i;
}
i=(i+1)%MAX_SIZE;
}
while(i!=(rear+1)%MAX_SIZE);
printf("%d not fount in queue \n",key);
return-1;
}
void display()
{
if(isEmpty())
{
printf("queue is empty\n");
return;
}

printf("circular queue:");
i=front;
do
{
printf("%d",queue[i]);
i=(i+1)%MAX_SIZE;
}
while(i!=(rear+1)%MAX_SIZE);
printf("\n");
}
int main()
{
int choice,data,key;
while(1)
{
printf("\ncircular queue operations:\n");
printf("1.add(enqueue)\n");
printf("2.delete(dequeue)\n");
printf("3.search\n");
printf("4.display\n");
printf("5.exit\n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter the element to add:");
scanf("%d",&data);
enqueue(data);
break;
case 2:
dequeue();
break;
case3:
printf("enter element to search:");
scanf("%d",&key);
search(key);
break;
case 4:
display();
break;
case 5:
exit(0);
default:
printf("invalid choice\n");
}
}
return 0;
}



