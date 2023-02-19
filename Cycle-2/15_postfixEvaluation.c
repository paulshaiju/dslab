//program to implement postfix evaluation//
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char p[20];
char s1[20];
int top=-1,top1=-1;
void postfix_eval()
{
	int i,op1,op2,result;
	char str[100];
	for(i=0;i<strlen(p);i++)
	{
		if(isdigit(p[i]))
		{
			str[0]=p[i];
			str[1]='\0';
			s1[++top1]=atoi(str);
		}
		else
		{
			op2=s1[top1--];
			op1=s1[top1--];
			switch(p[i])
			{
				case'+':
					result=op1+op2;
					break;
				case'-':
					result=op1-op2;
					break;
				case'*':
					result=op1*op2;
					break;
				case'/':
					result=op1/op2;
					break;
				case'^':
					result=op1^op2;
					break;
			}
			s1[++top1]=result;
		}
	}
	printf("\nResult=%d",s1[0]);
}
int main()
{
	printf("Enter postfix expression: ");
	gets(p);
	postfix_eval();
}
/* OUTPUT
Enter postfix expression: 23*45*+

Result=26 */
