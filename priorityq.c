#include<stdio.h>
#define size 10
int p[size];
int front;
int rear;
int i,j;
void create()
{
	front=rear=-1;
}
void check(int data)
{
	for(i=0;i<=rear;i++)
	{
		if(data>=p[i])
		{
			for(j=rear+1;j>i;j--)
			{
				p[j]=p[j-1];
				
			}
			p[i]=data;
			return;
			//swap(&data,&p[i]);
		}
		
	}
	p[i]=data;
}
void insertqueue(int data)
{
	if(rear==size-1)
	{
		printf("overflow");
		return;
	}
	if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		p[rear]=data;
		return;
	}
	else
		check(data);
	rear++;
}
void deletequeue(int data)
{
	if(front==-1 && rear==-1)
	{	
		printf("empty");
		return;
	}
	for(i=0;i<=rear;i++)
	{
		if(data==p[i])
		{
			for(;i<rear;i++)
			{
				p[i]=p[i+1];
			}
			p[i]=-99;
			rear--;
			if(rear==-1)
				front==-1;
			return;
		}
	}
}
void display()
{
	if(front==-1 && rear==-1)
	{	
		printf("empty");
		return;
	}
	for(;front<rear;front++)
	{
		printf("%d\t",p[front]);
	}
	front=0;
}
	
int main()
{
	int ch,ans,data;
	do
	{
		

		printf("\nEnter your choice:\n1:insertqueue\n2.dequeue\n3.display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter data: ");
				scanf("%d",&data);
				insertqueue(data);
				break;
			case 2:printf("enter data: ");
				scanf("%d",&data);
				deletequeue(data);
				break;
			case 3:display();
				break;
			default:printf("Error");
		}
	}while(ch!=4);
}
/*OUTPUT----
Enter your choice:
1:insertqueue
2.dequeue
3.display
1
enter data: 10

Enter your choice:
1:insertqueue
2.dequeue
3.display
1
enter data: 20

Enter your choice:
1:insertqueue
2.dequeue
3.display
1
enter data: 30

Enter your choice:
1:insertqueue
2.dequeue
3.display
1
enter data: 40

Enter your choice:
1:insertqueue
2.dequeue
3.display
3
40	30	20	10	
Enter your choice:
1:insertqueue
2.dequeue
3.display
2
enter data: 20

Enter your choice:
1:insertqueue
2.dequeue
3.display
3
40	30	10	
Enter your choice:
1:insertqueue
2.dequeue
3.display

*/
