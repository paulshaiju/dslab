//program to implement binary search using recursion//
#include <stdio.h>
int BinarySearch(int a[], int start, int end, int element){
   if (end >= start)
   {
      int middle = start + (end - start )/2;
      if (a[middle] == element)
         return middle;
      if (a[middle] > element)
         return BinarySearch(a, start, middle-1, element);
      return BinarySearch(a, middle+1, end, element);
   }
   return -1;
}
void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
int main()
{
   int a[10],n,element,flag=0;
   printf("Enter the limit: ");
   scanf("%d",&n);
   printf("Enter the elements: ");
   read(a,n);
   printf("Enter the element to be searched: ");
   scanf("%d",&element);
   flag = BinarySearch(a, 0, n-1, element);
   if(flag == -1 ) 
   {
      printf("Element not found in the array ");
   }
   else 
   {
      printf("Element found at index : %d",flag+1);
   }
   return 0;
}

/* OUTPUT
Enter the elements: 1
3
5 
10
Enter the element to be searched: 3
Element found at index : 2 */
