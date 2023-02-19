//program to implement polynomial addition//
#include <stdio.h>
struct poly
{
    int coef;
    int expo;
}p1[10],p2[10],p3[10];
int readpoly(struct poly[]);
int addpoly(struct poly[],struct poly[],int,int,struct poly[]);
void displaypoly(struct poly[],int terms);
int main()
{
    int t1,t2,t3;
   
    t1=readpoly(p1);
    printf("\nFirst Polynomial:\n");
    displaypoly(p1,t1);
   
    t2=readpoly(p2);
    printf("\nsecond Polynomial:\n");
    displaypoly(p2,t2);
   
    t3=addpoly(p1,p2,t1,t2,p3);
    printf("\n\nResultant Polynomial:\n");
    displaypoly(p3,t3);
}
int readpoly(struct poly p[])
{
    int n,i;
    printf("\nEnter the no. of terms:");
    scanf("%d",&n);
    printf("Enter the coef and expo in decending order\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the coef(%d):",i+1);
        scanf("%d",&p[i].coef);
        printf("Enter the expo(%d):",i+1);
        scanf("%d",&p[i].expo);
    }
    return(n);
}
void displaypoly(struct poly p[],int n)
{
    int k;
    for(k=0;k<n-1;k++)
    printf("%d(x^%d)+",p[k].coef,p[k].expo);
    printf("%d(x^%d)",p[n-1].coef,p[n-1].expo);
   
}
int addpoly(struct poly p1[10],struct poly p2[10],int t1,int t2, struct poly p3[10])
{
    int i=0,k=0,j=0;
    while(i<t1&&j<t2)
    {
        if(p1[i].expo==p2[j].expo)
        {
            p3[k].coef=p1[i].coef+p2[j].coef;
            p3[k].expo=p1[i].expo;
            i++;j++;k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            p3[k].coef=p1[i].coef;
            p3[k].expo=p1[i].expo;
            i++; k++;
        }
        else
        {
            p3[k].coef=p2[j].coef;
            p3[k].expo=p2[j].expo;
            j++; k++;
        }
    }

    while(i<t1)
    {
        p3[k].coef=p1[i].coef;
        p3[k].expo=p1[i].expo;
        i++; k++;
    }
    while(j<t2)
    {
        p3[k].coef=p2[j].coef;
        p3[k].expo=p2[j].expo;
        j++; k++;
    }
    return(k);
}

/* OUTPUT
Enter the no. of terms:2
Enter the coef and expo in decending order
Enter the coef(1):2
Enter the expo(1):1
Enter the coef(2):3
Enter the expo(2):0

First Polynomial:
2(x^1)+3(x^0)
Enter the no. of terms:2
Enter the coef and expo in decending order
Enter the coef(1):5
Enter the expo(1):1
Enter the coef(2):2
Enter the expo(2):0

second Polynomial:
5(x^1)+2(x^0)

Resultant Polynomial:
7(x^1)+5(x^0) */
