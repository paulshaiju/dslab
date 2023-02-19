//program to convert an infix expression into a prefix expression//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
char a[20], p[20];
char s[20];
int s1[20],top=-1,top1=-1;
int precedence(char c)
{
    switch(c)
    {
        case '+':
			return 1;
        case '-': 
			return 1;
        case '*':
			return 2;
        case '/': 
			return 2;
        case '^': 
			return 3;
    }
    return 0;
}
void infix_to_prefix()
{
    int i=0, j=0;
    char x,y;
   char *strrev(char *a);
    while(a[i]!='\0')
    {
        if(isdigit(a[i]))
            p[j++]=a[i];
        else if(a[i]==')')
            s[++top]=a[i];
        else if(a[i]=='(')
        {
            while (s[top]!=')')
                p[j++]=s[top--];
            top--;
        }
        else
        {
            x=a[i];
            y=s[top];
            if(top==-1 || y==')' || precedence(y)<=precedence(x))
                s[++top]=a[i];
            else
            {
                while(precedence(x)<precedence(y) && y!= ')' && top!=-1)
                {
                    p[j++]=s[top--];
                    y=s[top];
                }
                s[++top]=x;
            }
        }
        i++;
    }
    while(top!=-1)
        p[j++]=s[top--];
    p[j]='\0';
   
    printf("Prefix exp is %s",strrev(p));
}

int main()
{
    printf("Enter Infix expression:");
    gets(a);
    infix_to_prefix();
   
}

/* OUTPUT
Enter Infix expression:123+-/*
Prefix exp is +-/*321 */

