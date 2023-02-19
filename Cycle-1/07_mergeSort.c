//program to implement merge sort
#include <stdio.h>  
void merge(int a[], int first, int mid, int last)    
{    
    int i, j, k;  
    int n1 = mid - first + 1;    
    int n2 = last - mid;    
    int LeftArray[n1], RightArray[n2];  
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[first + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
    i = 0;
    j = 0;  
    k = first;  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int first, int last)  
{  
    if (first < last)   
    {  
        int mid = (first + last) / 2;  
        mergeSort(a, first, mid);  
        mergeSort(a, mid + 1, last);  
        merge(a, first, mid, last);  
    }  
}
void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
  
int main()  
{  
    int a[10],n;
    printf("Enter the limit: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    read(a,n);
    printf("Before sorting array elements are - \n");  
    display(a, n);  
    mergeSort(a, 0, n - 1);  
    printf("After sorting array elements are - \n");  
    display(a, n);  
    return 0;  
}

/* OUTPUT
Enter the limit: 4
Enter the elements: 1
6
2
5
Before sorting array elements are - 
1 6 2 5 
After sorting array elements are - 
1 2 5 6 */

