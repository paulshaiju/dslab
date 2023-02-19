//program to add two sparse matrices//
#include <stdio.h>
#include <stdlib.h>
void read(int a[10][10], int m, int n)
{
    int i, j;
    printf("Enter elements of matrix\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void print(int s[100][3])
{
    int i, n;
    n = s[0][2];
    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}
void sparse(int a[10][10], int m, int n, int s[100][3])
{
    int i, j, k;
    k = 1;
    s[0][0] = m;
    s[0][1] = n;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
        s[0][2] = k - 1;
    }
}
void add(int b1[50][3],int b2[50][3],int b3[50][3])
{
int t1,t2,i,j,k;
if(b1[0][0]!=b2[0][0]||b1[0][1]!=b2[0][1])
    {
printf("You have entered invalid matrix!!Size must be equal");
exit (0);
    }
   t1=b1[0][2];
   t2=b2[0][2];
   i=j=k=0;
   b3[0][0]=b1[0][0];
   b3[0][1]=b1[0][1];
   while(i<=t1&&j<=t2)
    {
if(b1[i][0]<b2[j][0])      
{
    b3[k][0]=b1[i][0];
b3[k][1]=b1[i][1];
b3[k][2]=b1[i][2];
k++;
i++;
}
else if(b2[j][0]<b1[i][0])      
{
b3[k][0]=b2[j][0];
b3[k][1]=b2[j][1];
b3[k][2]=b2[j][2];
    k++;
j++;
}
else if(b1[i][1]<b2[j][1])      
{
b3[k][0]=b1[i][0];
b3[k][1]=b1[i][1];
b3[k][2]=b1[i][2];
k++;
i++;
    }
else if(b2[j][1]<b1[i][1])      
{
b3[k][0]=b2[j][0];
b3[k][1]=b2[j][1];
b3[k][2]=b2[j][2];
k++;
j++;
}
else
{
b3[k][0]=b1[i][0];
b3[k][1]=b1[i][1];
b3[k][2]=b1[i][2]+b2[j][2];
k++;
i++;
j++;
}
    }
while(i<=t1)
    {
b3[k][0]=b1[i][0];
b3[k][1]=b1[i][1];
b3[k][2]=b1[i][2];
i++;
k++;
    }
while(j<=t2)
    {
b3[k][0]=b2[j][0];
b3[k][1]=b1[j][1];
b3[k][2]=b1[j][2];
j++;
k++;
    }
b3[0][2]=k-1;
}
int main()
{
    int a[10][10], s1[100][3] ,s3[100][3],s2[100][3], m, n,p,q,b[10][10];
    printf("Enter the size of matrix 1 (rows, columns): ");
    scanf("%d%d", &m, &n);
    read(a,m,n);
    printf("Enter the size of matrix 2 (rows, columns): ");
    scanf("%d%d", &p, &q);
    read(b,p,q);
    sparse(b,p,q,s2);
    sparse(a,m,n,s1);
    printf("Sparse matrix 1 + Sparse matrix 2:\n");
    print(s1); printf("+\n"); print(s2);
    add(s1,s2,s3); printf("\nResultant sparse matrix:\n"); print(s3);
 return 0;
}

/* OUTPUT
Enter the size of matrix 1 (rows, columns): 3
3
Enter elements of matrix
[0][0]: 0
[0][1]: 0
[0][2]: 2
[1][0]: 0
[1][1]: 3
[1][2]: 0
[2][0]: 5
[2][1]: 0
[2][2]: 6
Enter the size of matrix 2 (rows, columns): 3
3
Enter elements of matrix
[0][0]: 0
[0][1]: 0
[0][2]: 2
[1][0]: 0
[1][1]: 4
[1][2]: 0
[2][0]: 8
[2][1]: 0
[2][2]: 0
Sparse matrix 1 + Sparse matrix 2:
3       3       4
0       2       2
1       1       3
2       0       5
2       2       6
+
3       3       3
0       2       2
1       1       4
2       0       8

Resultant sparse matrix:
3       3       4
0       2       4
1       1       7
2       0       13
2       2       6 */
