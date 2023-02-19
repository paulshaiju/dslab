//program to implement linear search//
#include<stdio.h>
void
read (int a[], int n)
{
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
}

void
linearsearch (int a[], int n, int search)
{
  int i;
  for (i = 0; i < n; i++)
    {
      if (search == a[i])
	{
	  printf ("Element found at index %d", i + 1);
	  break;
	}
    }
  if (search != a[i])
    {
      printf ("Element not found");
    }
}

int
main ()
{
  int a[10], i, n, search;
  printf ("Enter the limit: ");
  scanf ("%d", &n);
  printf ("Enter the elements:\n");
  read (a, n);
  printf ("Enter the element to be searched: ");
  scanf ("%d", &search);
  linearsearch (a, n, search);
  return 0;
}

/* OUTPUT
Enter the limit: 4
Enter the elements:
1
4
2
5
Enter the element to be searched: 4
Element found at index 2

COMPILATION STEP
gcc lsearch.c -o lsearch

EXECUTION STEP
./lsearch */
