//program to implement selection sort//
#include <stdio.h>
void read(int a[],int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void display(int a[],int n)
{
     for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
void selectionsort(int a[], int n)
{
    int i, j, position, swap;
    for(i = 0; i < (n - 1); i++)
    {
        position=i;
        for(j = i + 1; j < n; j++)
        {
            if(a[position]>a[j])
                position=j;
        }
        if(position != i)
        {
            swap=a[i];
            a[i]=a[position];
            a[position]=swap;
        }
    }
}
int main()
{
    int a[100], n, i, j, position, swap;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d Numbers:\n", n);
    read(a,n);
    selectionsort(a,n);
    printf("Sorted Array:\n");
    display(a,n);
    return 0;
}

/* OUTPUT
Enter number of elements: 4
Enter 4 Numbers:
1
6
5
9
Sorted Array:
1	5	6	9	*/

