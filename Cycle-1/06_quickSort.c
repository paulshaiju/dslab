//program to implement quick sort//
#include<stdio.h>
void quicksort(int a[25],int first,int last)
{
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);

   }
}
void read(int a[],int count)
{
    for(int i=0;i<count;i++)
      scanf("%d",&a[i]);
}

void display(int a[],int count)
{
    for(int i=0;i<count;i++)
      printf(" %d",a[i]);
}

int main(){
   int i, count, a[25];
   printf("Enter the limit: ");
   scanf("%d",&count);
   printf("Enter %d elements: ", count);
   read(a,count);
   quicksort(a,0,count-1);
   printf("Order of Sorted elements: ");
   display(a,count);
   return 0;
}

/* OUTPUT
Enter the limit: 4
Enter 4 elements: 1
6
4
9
Order of Sorted elements:  1 4 6 9 */

