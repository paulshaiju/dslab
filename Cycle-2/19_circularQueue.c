//program to implement a circular queue using arrays//
#include <stdio.h>
int a[20],size,front,rear;
void ENQUEUE_CQ(int item)
{
    if((rear+1)%size==front)
        printf("Queue is full. Insertion is not possible.");
    else if(rear==-1)
    {
        front=0; rear=0; a[rear]=item;
    }
    else
    {
        rear=(rear+1)%size;
        a[rear]=item;
    }
}
void DEQUEUE_CQ()
{
    if(front==-1)
        printf("Queue is empty");
        else if(front==rear)
        {
            printf("Deleted item is %d",a[front]);
            front=-1; rear=-1;
        }
        else
        {
            printf("Deleted item is %d",a[front]);
            front=(front+1)%size;
        }
}
void DISPLAY_CQ()
{
    int i;
    if(front==-1)
        printf("Queue is empty");
    else if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",a[i]);
    }
    else
    {
        for(i=front;i<=size-1;i++)
            printf("%d\t",a[i]);
        for(i=0;i<=rear;i++)
            printf("%d\t",a[i]);
    }
}
int main()
{
    int item,opt;
    front=-1;
    rear=-1;
    printf("Enter the size of the Queue:");
    scanf("%d",&size);
    do
    {
        printf("\nEnter the option:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("Enter the item to be inserted: ");
                    scanf("%d",&item);
                    ENQUEUE_CQ(item);
                    break;
            case 2: DEQUEUE_CQ();
                    break;
            case 3: DISPLAY_CQ();
                    break;
            case 4:break;
            default: printf("Invalid option");
        }
    }while(opt!=4);
}
/* OUTPUT
Enter the size of the Queue:4

Enter the option:
1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the item to be inserted: 3

Enter the option:
1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the item to be inserted: 5

Enter the option:
1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the item to be inserted: 2

Enter the option:
1.Enqueue
2.Dequeue
3.Display
4.Exit
3
3       5       2
Enter the option:
1.Enqueue
2.Dequeue
3.Display
4.Exit
2
Deleted item is 3
Enter the option:
1.Enqueue
2.Dequeue
3.Display
4.Exit
3
5       2
Enter the option:
1.Enqueue
2.Dequeue
3.Display
4.Exit */
