/* exp 31
heap sort */
#include <stdio.h>
void printArray(int A[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d ",A[i]);
}
}

void heapify(int A[],int n,int i)
{
int largest=i;
int left=2*i+1;
int right=2*i+2;
if(left<n && A[left]>A[largest])
{
largest=left;
}
if(right<n && A[right]>A[largest])
{
largest=right;
}
if(largest!=i)
{
int temp=A[i];
A[i]=A[largest];
A[largest]=temp;
heapify(A, n, largest);
}
}

void BuildMaxHeap(int A[],int n)
{
int i;
for(i=n/2 - 1; i>=0; i--)
{
heapify(A,n,i);
}
}
void heapSort(int A[],int n)
{
int i;
BuildMaxHeap(A,n);
for(i=n-1;i>=0;i--)
{
int temp=A[0];
A[0]=A[i];
A[i]=temp;
heapify(A,i,0);
}
}

void main()
{
int n,i,A[50];
printf("Enter the number of elements : ");
scanf("%d",&n);
printf("Enter %d elements : ",n);
for(i=0;i<n;i++)
{
scanf("%d",&A[i]);
}
printf("Before sorting array elements are -\n");
printArray(A,n);
heapSort(A,n);
printf("\nAfter sorting array elements are -\n");
printArray(A,n);
}
/* Enter the number of elements : 4
Enter 4 elements : 4 1 3 2
Before sorting array elements are -
4 1 3 2 
After sorting array elements are -
1 2 3 4 */