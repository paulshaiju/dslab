/* exp: 28
pgm to count no. of nodes in a linked list */
#include <stdio.h>
#include <stdlib.h>
 int i=0;
struct node
{
    int data;
    struct node *link;
};
struct node *head;
void count()
{
    struct node *ptr;
    if(head==NULL)
        printf("\nLinked list is empty...");
    else
    {
       
        ptr=head;
        printf("\nNumber of Linked list elements are: ");
        while(ptr!=NULL)
        {
            i=i+1;
           
            ptr=ptr->link;
        }
        printf("%d",i);
       
    }
}
void insert_front(int x)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->link=head;
    head=new;
}

int main()
{
    int opt,x;
    do
    {
        printf("\nEnter the option\n1.Insert at front\n2.count\n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter the new data: ");
            scanf("%d",&x);
            insert_front(x);
            break;
       
        case 2:
          count();
            break;
       
        }
    } while(opt!=2);
   
}
/* OUTPUT:: 
Enter the option
1.Insert at front
2.count
1
Enter the new data: 22
Enter the option
1.Insert at front
2.count
1
Enter the new data: 33
Enter the option
1.Insert at front
2.count
2
Number of Linked list elements are: 2 */