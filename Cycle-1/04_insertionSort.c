//program to perform insertion sort in an one dimensional array//
#include<stdio.h>
void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[],int n)
{
   for( int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    } 
}
int insertionsort(int a[],int n)
{
    int temp,i,j;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int a[10],n,i;
    printf("Enter the limit: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    read(a,n);
    insertionsort(a,n);
    printf("The sorted list is: \n");
    display(a,n);
}

/* OUTPUT
Enter the limit: 5
Enter the elements: 1
6
4
9
5
The sorted list is: 
1	4	5	6	9	*/












