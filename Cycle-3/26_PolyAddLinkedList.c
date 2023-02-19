//Polynomial Addition using Linked List
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef,expo;
    struct node *link;
};
struct node *phead, *qhead, *rhead;
struct node * readpoly()
{
    struct node *new,*ptr,*head=NULL;
    int n,i;
    printf("\nEnter the total no. of terms in the polynomial:");
    scanf("%d",&n);
    printf("Enter the coef and expo: \n");
    for(i=1;i<=n;i++)
    {
        printf("Enter (coef%d,expo%d)",i,i);
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->coef);
        scanf("%d",&new->expo);
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            ptr=head;
        }
        else
        {
            ptr->link=new;
            ptr=new;
        }
    }
    return(head);
}
void displaypoly(struct node *head)
{
    struct node *ptr;
    if(head==NULL)
        printf("Polynomial is empty");
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%dx^%d + ",ptr->coef, ptr->expo);
            ptr=ptr->link;
        }
        printf("%dx^%d\t",ptr->coef, ptr->expo);
    }
}
struct node *addpoly()
{
    struct node *new, *p,*q,*r,*head=NULL;
    p=phead;
    q=qhead;
    while(p!=NULL && q!=NULL)
    {
        if(p->expo==q->expo)
        {
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=p->coef+q->coef;
            new->expo=p->expo;
            new->link=NULL;
            p=p->link;
            q=q->link;
        }
        else if(p->expo>q->expo)
        {
            new=(struct node *)malloc(sizeof(struct node ));
            new->coef=p->coef;
            new->expo=p->expo;
            new->link=NULL;
            p=p->link;
        }
        else
        {
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=q->coef;
            new->expo=q->expo;
            new->link=NULL;
            q=q->link;
        }
        if(head==NULL)
        {
            head=new;
            r=head;
        }
        else
        {
            r->link=new;
            r=new;
        }
    }
    while(p!=NULL)
    {
        new=(struct node *)malloc(sizeof(struct node));
        new->coef=p->coef;
        new->expo=p->expo;
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            r=head;
        }
        else
        {
            r->link=new;
            r=new;
        }
        p=p->link;
    }
    while(q!=NULL)
    {
        new=(struct node *)malloc(sizeof(struct node));
        new->coef=q->coef;
        new->expo=q->expo;
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            r=head;
        }
        else
        {
            r->link=new;
            r=new;
        }
        q=q->link;
    }
     return(head);   
    
}
int main()
{
    //read the first polynomial
    printf("\nEnter the details of First Polynomial:");
    phead=readpoly();
    //read 2nd poly.
    printf("\nEnter the details of 2nd polynomial: ");
    qhead=readpoly();
    printf("\nFirst pol;ynomial: ");
    displaypoly(phead);
    printf("\nSecond polynomial: ");
    displaypoly(qhead);
    //add:
    rhead=addpoly();
    printf("\nResultant poly(SUM): ");
    displaypoly(rhead);
}
/*
Output:
Enter the details of First Polynomial:
Enter the total no. of terms in the polynomial:2
Enter the coef and expo: 
Enter (coef1,expo1)2 3
Enter (coef2,expo2)4 5
Enter the details of 2nd polynomial: 
Enter the total no. of terms in the polynomial:2
Enter the coef and expo: 
Enter (coef1,expo1)3 3
Enter (coef2,expo2)6 5
First pol;ynomial: 2x^3 + 4x^5	
Second polynomial: 3x^3 + 6x^5	
Resultant poly(SUM): 5x^3 + 10x^5
*/
