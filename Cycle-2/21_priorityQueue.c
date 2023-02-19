//program to implement a priority queue using arrays//
#include <stdio.h>
int size,front,rear;
struct PQ
{
    int item,priority;
}a[20];
void display()
{
    int i;
    if(front==-1)
        printf("Queue is empty");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",a[i].item);
    }
}
void enqueue(int item, int priority)
{
    int i,loc;
    if(front==0 && rear==size-1)
        printf("Queue is full");
    else if(front==-1)
    {
        front=0; rear=0;
        a[rear].item=item;
        a[rear].priority=priority;
    }
    else
    {
        if(rear==size-1)
        {
            for(i=front;i<=rear;i++)
                a[i-1]=a[i];
            front--;
            rear--;
        }
        for(i=rear;i>=front;i--)
        {
            if(a[i].priority<priority)
            {
                break;
            }
        }
        loc=i+1;
        for(i=rear;i>=loc;i--)
        {
            a[i+1]=a[i];
        }
        a[loc].item=item;
        a[loc].priority=priority;
        rear++;
    }
}
void dequeue()
{
    if(front==-1)
        printf("Queue is empty");
    else if(front==rear)
    {
        printf("Deleted item is %d",a[front].item);
        front=-1;rear=-1;
    }
    else
    {
        printf("Deleted item is:%d",a[front].item);
        front++;
    }
}
int main()
{
    int opt,item,prio;
    front=-1; rear=-1;
    printf("Enter the size:");
    scanf("%d",&size);
    do
    {
        printf("\nEnter the option\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:printf("Enter the item and priority");
            scanf("%d%d",&item,&prio);
            enqueue(item,prio);
            break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            case 4: printf("Exiting..");
                    break;
            default: printf("invalid option");
        }
    }while(opt!=4);
   
}

/* OUTPUT
Enter the size:5

Enter the option
1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the item and priority2
6

Enter the option
1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the item and priority3
2

Enter the option
1.Enqueue
2.Dequeue
3.Display
4.Exit
2
Deleted item is:3
Enter the option
1.Enqueue
2.Dequeue
3.Display
4.Exit
3
2
Enter the option
1.Enqueue
2.Dequeue
3.Display
4.Exit
4
Exiting.. */
