//program to implement queue using arrays//
#include <stdio.h>
int a[20],size,front,rear;
void ENQUEUE(int item)
{
    if(rear==size-1)
    printf("Queue is full. Insertion is not possible");
    else if(rear==-1)
    {
        front=0; rear= 0;
        a[rear]=item;
    }
    else
    {
        rear++;
        a[rear]=item;
    }
   
}
void DEQUEUE()
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
        front++;
    }
}
void DISPLAY()
{
    int i;
    if(front==-1)
    printf("Queue is empty");
    else
    {
        for(i=front;i<=rear;i++)
        printf("%d\t",a[i]);
    }
}
int main()
{
    int item,opt;
    front=-1;
    rear=-1;
    printf("Enter the size of the queue:");
    scanf("%d",&size);
    do
    {
        printf("\nEnter the option:\n");
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("Enter the item to be inserted:");
                    scanf("%d",&item);
                    ENQUEUE(item);
                    break;
            case 2: DEQUEUE();
                    break;
            case 3:DISPLAY();
                    break;
            case 4:printf("Exiting\n");
                    break;
            default:printf("Invalid option...");
        }
    }while(opt!=4);
}

/* OUTPUT
Enter the size of the queue:5

Enter the option:
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
4.EXIT
1
Enter the item to be inserted:2

Enter the option:
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
4.EXIT
1
Enter the item to be inserted:6

Enter the option:
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
4.EXIT
3
2       6
Enter the option:
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
4.EXIT
2
Deleted item is 2
Enter the option:
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
4.EXIT
3
6
Enter the option:
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
4.EXIT
4
Exiting */
