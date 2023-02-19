//exp::23
//pgm to implement stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top;
void display()
{
    struct node *ptr;
    if(top==NULL)
        printf("\nStack is empty...");
    else
    {
        ptr=top;
        printf("\nStack elements are: ");
        while(ptr!=NULL)
        {
            printf("%d-->",ptr->data);
			ptr=ptr->link;
			if (ptr==NULL)
				printf("NULL");
        }
    }
}
void push(int item)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=item;
    new->link=top;
    top=new;
    display();
}
void pop()
{
    struct node *temp;
    if(top==NULL)
        printf("\nStack is empty.");
    else
    {
        temp=top;
        printf("\nPoped item is %d",top->data);
        top=top->link;
        free(temp);
        display();
    }
}
int main()
{
    int opt,item;
    do
    {
        printf("\nEnter the option\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("Enter the new data: ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2: pop();
                    break;
            case 3: display();
        }
    }while(opt!=4);
}

/*
OUTPUT::

Enter the option
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter the new data: 24

Stack elements are: 24-->NULL
Enter the option
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter the new data: 4

Stack elements are: 4-->24-->NULL
Enter the option
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter the new data: 8

Stack elements are: 8-->4-->24-->NULL
Enter the option
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter the new data: 40

Stack elements are: 40-->8-->4-->24-->NULL
Enter the option
1.PUSH
2.POP
3.DISPLAY
4.EXIT
2

Poped item is 40
Stack elements are: 8-->4-->24-->NULL
Enter the option
1.PUSH
2.POP
3.DISPLAY
4.EXIT
3

Stack elements are: 8-->4-->24-->NULL
Enter the option
1.PUSH
2.POP
3.DISPLAY
4.EXIT
4 */
