//exp::22
//pgm to implement singly linked list (BASIC OPERATIONS)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head;
void display()
{
    struct node *ptr;
    if(head==NULL)
        printf("\nLinked list is empty...");
    else
    {
        ptr=head;
        printf("\nLinked list elements are: ");
        while(ptr!=NULL)
        {
			printf("%d-->",ptr->data);
			ptr=ptr->link;
			if (ptr==NULL)
				printf("NULL");
        }
        
    }
}
void insert_front(int x)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->link=head;
    head=new;
    display();
}
void insert_end(int x)
{
    struct node *new,*ptr;
    new=(struct node *)malloc(sizeof(struct node ));
    new->data=x;
    new->link=NULL;
    if(head==NULL)
        head=new;
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=new;
    }
    display();
}
void insert_after(int key,int x)
{
    struct node *new, *ptr;
    if(head==NULL)
        printf("Search key not found.Insertion not possible");
    else
    {
        ptr=head;
        while(ptr->data!=key&&ptr->link!=NULL)
            ptr=ptr->link;
        if(ptr->data!=key)
            printf("Search key not found.Insertion not possible");
        else
        {
            new=(struct node *)malloc(sizeof(struct node));
            new->data=x;
            new->link=ptr->link;
            ptr->link=new;
        }
    }
    display();
}
void delete_front()
{
    struct node *temp;
    if(head==NULL)
        printf("List is empty. Deletion not possible");
    else
    {
        temp=head;
        head=head->link;
        free(temp);
    }
    display();
}
void delete_end()
{
    struct node *prev, *curr, *temp;
    if(head==NULL)
        printf("List is empty. Deletion not possible");
    else if(head->link==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        prev=head;
        curr=head->link;
        while(curr->link!=NULL)
        {
            prev=curr;
            curr=curr->link;
        }
        prev->link=NULL;
        free(curr);
    }
    display();
}
void delete_any(int key)
{
    struct node *prev, *curr, *temp;
    if(head==NULL)
        printf("List is empty.Deleteion not possible");
    else if(head->data==key)
    {
        temp=head;
        head=head->link;
        free(temp);
    }
    else
    {
        prev=head;
        curr=head;
        while(curr->data!=key&&curr->link!=NULL)
        {
            prev=curr;
            curr=curr->link;
        }
        if(curr->data!=key)
            printf("Search data not found.Deletion not possible");
        else
        {
            prev->link=curr->link;
            free(curr);
        }
    }
    display();
}
int main()
{
    int opt,x,key;
    do
    {
        printf("\nEnter the option\n1.Insert at front\n2.Insert at end\n3.Insert after a specified node\n4.Delete from front\n5.Delete from end\n6.Delete the specified node\n7.display\n8.exit\n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter the new data: ");
            scanf("%d",&x);
            insert_front(x);
            break;
        case 2:
            printf("Enter the new data: ");
            scanf("%d",&x);
            insert_end(x);
            break;
        case 3:
            printf("Enter the search key:");
            scanf("%d",&key);
            printf("Enter the new data: ");
            scanf("%d",&x);
            insert_after(key,x);
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter the node to be deleted: ");
            scanf("%d",&key);
            delete_any(key);
            break;
        case 7:
            display();
            break;
        case 8:
            break;
        }
    } while(opt!=8);
}

/*
OUTPUT::
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
1
Enter the new data: 21

Linked list elements are: 21-->NULL
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
2
Enter the new data: 45

Linked list elements are: 21-->45-->NULL
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
3
Enter the search key:45
Enter the new data: 32

Linked list elements are: 21-->45-->32-->NULL
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
1
Enter the new data: 30

Linked list elements are: 30-->21-->45-->32-->NULL
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
4

Linked list elements are: 21-->45-->32-->NULL
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
5

Linked list elements are: 21-->45-->NULL
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
6
Enter the node to be deleted: 21

Linked list elements are: 45-->NULL
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
7

Linked list elements are: 45-->NULL
Enter the option
1.Insert at front
2.Insert at end
3.Insert after a specified node
4.Delete from front
5.Delete from end
6.Delete the specified node
7.display
8.exit
8 */
