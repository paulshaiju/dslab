//program to add two sparse matrices//
#include <stdio.h>
void read(int a[10][10], int m, int n);
void print(int s[100][3]);
void sparse(int a[10][10], int m, int n, int s[100][3]);
void transpose(int b1[][3],int b2[][3]);
int main()
{
    int a[10][10], t[100][3],s[100][3], m, n;
    printf("\nEnter the size of matrix (rows, columns): ");
    scanf("%d%d", &m, &n);
    read(a,m,n);
    sparse(a,m,n,s);
    transpose(s,t);
    printf("\nBefore Transpose:"); print(s);
    printf("\nAfter Transpose:"); print(t);
    return 0;
}
void read(int a[10][10], int m, int n)
{
    int i, j;
    printf("\nEnter elements of matrix\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
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
void print(int s[100][3])
{
    int i, n;
    n = s[0][2];
    printf("\nSparse form - list of 3 triples\n\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}
void transpose(int b1[][3],int b2[][3])
{
int i,j,k,n;
b2[0][0]=b1[0][1];
b2[0][1]=b1[0][0];
b2[0][2]=b1[0][2];
k=1;
n=b1[0][2];
for(i=0;i<b1[0][1];i++)
for(j=1;j<=n;j++)
if(i==b1[j][1])
{
b2[k][0]=i;
b2[k][1]=b1[j][0];
b2[k][2]=b1[j][2];
k++;
}
}

/* OUTPUT
Enter the size of matrix (rows, columns): 3
3

Enter elements of matrix
[0][0]: 0
[0][1]: 0
[0][2]: 1
[1][0]: 2
[1][1]: 0
[1][2]: 3
[2][0]: 0
[2][1]: 5
[2][2]: 0

Before Transpose:
Sparse form - list of 3 triples

3       3       4
0       2       1
1       0       2
1       2       3
2       1       5

After Transpose:
Sparse form - list of 3 triples

3       3       4
0       1       2
1       2       5
2       0       1
2       1       3 */
