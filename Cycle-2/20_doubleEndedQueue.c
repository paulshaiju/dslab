 //program to implement a double-ended queue using arrays//
 #include <stdio.h>
 int a[20],size,rear,front;
 void push(int item)
 {
     int i;
     if(front==0 && rear==size-1)
        printf("Double ended queue is full.");
    else if(rear==-1)
    {
        front=0; rear=0; a[front]=item;
    }
    else if(front>0)
    {
        front--;
        a[front]=item;
    }
    else
    {
        for(i=rear;i>=front;i--)
            a[i+1]=a[i];
        a[front]=item;
        rear++;
    }
 }
 void inject(int item)
 {
     int i;
     if(front==0 && rear==size-1)
        printf("Double ended queue is full.");
    else if(rear==-1)
    {
        front=0; rear=0; a[rear]=item;
    }
    else if(rear<size-1)
    {
        rear++;
        a[rear]=item;
    }
    else
    {
        for(i=front;i<=rear;i--)
            a[i-1]=a[i];
        a[rear]=item;
        front--;
    }
 }
 void reject()
 {
     if(front==-1)
        printf("Double ended queue is empty");
    else if(front==rear)
    {
        printf("Deleted item is %d",a[front]);
        front=-1; rear=-1;
    }
    else
    {
        printf("Deleted item is %d",a[rear]);
        rear--;
    }
 }
 void pop()
 {
     if(front==-1)
        printf("Double ended queue is empty");
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
  void display()
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
    printf("Enter the size of the double ended queue:");
    scanf("%d",&size);
    do
    {
        printf("\nEnter the option:\n");
        printf("1.push\n2.pop\n3.inject\n4.reject\n5.display\n6.exit\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("Enter the item to be inserted: ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2: pop();
                    break;
            case 3: printf("Enter the item to be inserted: ");
                    scanf("%d",&item);
                    inject(item);
                    break;
            case 4:reject();
                    break;
            case 5: display();
                    break;
            case 6: printf("Exiting...");
                    break;
            default: printf("Invalid option");
        }
    }while(opt!=6);
}
/* OUTPUT
Enter the size of the double ended queue:5

Enter the option:
1.push
2.pop
3.inject
4.reject
5.display
6.exit
1
Enter the item to be inserted: 5

Enter the option:
1.push
2.pop
3.inject
4.reject
5.display
6.exit
1
Enter the item to be inserted: 2

Enter the option:
1.push
2.pop
3.inject
4.reject
5.display
6.exit
3
Enter the item to be inserted: 3

Enter the option:
1.push
2.pop
3.inject
4.reject
5.display
6.exit
2
Deleted item is 2
Enter the option:
1.push
2.pop
3.inject
4.reject
5.display
6.exit
4
Deleted item is 3
Enter the option:
1.push
2.pop
3.inject
4.reject
5.display
6.exit
5
5
Enter the option:
1.push
2.pop
3.inject
4.reject
5.display
6.exit */
