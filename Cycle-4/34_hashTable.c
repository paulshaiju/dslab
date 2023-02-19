//program to implement a hash table using the hash function H(k)=k%10
#include<stdio.h>
#include<stdio.h>
struct set
{
	int key;
	int data;
};
struct set A[10];
int size=10;
void insert(int key, int data)
{
	int index=key%size;
	if(A[index].data==-1)
	{
		A[index].key=key;
		A[index].data=data;
	}
	else
	{
		printf("\n Collision occured \n");
	}
}
void delete_element(int key)
{
	int index= key%size;
	if(A[index].data==-1)
		printf("\nThis key does not exist \n");
	else
	{
		A[index].key=-1;
		A[index].data=-1;
	}
}
void display()
{
	int i;
	for(i=0;i<size;i++)
	{
		if(A[i].data==-1)
			printf("\n A[%d]: /",i);
		else
			printf("\n A[%d]: (%d %d) \t",i,A[i].key,A[i].data);
	}
}	
int main()
{
	 int choice,key,data,i;
	 for(i=0;i<size;i++)
	 {
		 A[i].key=-1;
		 A[i].data=-1;
	 }
	 do
	 {
		 printf("\n1.Insert item in the Hash table"
				"\n2.Remove item from the Hash Table"
				"\n3.Display a Hash Table"
				"\n4.Exit"
				"\n\n Please enter your choice: ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1: printf("Enter the key -:\t");
							scanf("%d",&key);
							printf("Enter data -:\t");
							scanf("%d",&data);
							insert(key,data);
							break;
					case 2: 
							printf("Enter the key to delete -:");
							scanf("%d",&key);
							delete_element(key);
							break;
					case 3: display();
							break;
				}
	}while(choice!=4);
}

/* OUTPUT
1.Insert item in the Hash table
2.Remove item from the Hash Table
3.Display a Hash Table
4.Exit

 Please enter your choice: 3

 A[0]: /
 A[1]: /
 A[2]: /
 A[3]: /
 A[4]: /
 A[5]: /
 A[6]: /
 A[7]: /
 A[8]: /
 A[9]: /
1.Insert item in the Hash table
2.Remove item from the Hash Table
3.Display a Hash Table
4.Exit

 Please enter your choice: 1
Enter the key -:        15
Enter data -:   20

1.Insert item in the Hash table
2.Remove item from the Hash Table
3.Display a Hash Table
4.Exit

 Please enter your choice: 3

 A[0]: /
 A[1]: /
 A[2]: /
 A[3]: /
 A[4]: /
 A[5]: (15 20)
 A[6]: /
 A[7]: /
 A[8]: /
 A[9]: /
1.Insert item in the Hash table
2.Remove item from the Hash Table
3.Display a Hash Table
4.Exit

 Please enter your choice: 1
Enter the key -:        28
Enter data -:   33

1.Insert item in the Hash table
2.Remove item from the Hash Table
3.Display a Hash Table
4.Exit

 Please enter your choice: 3

 A[0]: /
 A[1]: /
 A[2]: /
 A[3]: /
 A[4]: /
 A[5]: (15 20)
 A[6]: /
 A[7]: /
 A[8]: (28 33)
 A[9]: /
1.Insert item in the Hash table
2.Remove item from the Hash Table
3.Display a Hash Table
4.Exit

 Please enter your choice: 2
Enter the key to delete -:28

1.Insert item in the Hash table
2.Remove item from the Hash Table
3.Display a Hash Table
4.Exit

 Please enter your choice: 3

 A[0]: /
 A[1]: /
 A[2]: /
 A[3]: /
 A[4]: /
 A[5]: (15 20)
 A[6]: /
 A[7]: /
 A[8]: /
 A[9]: /
1.Insert item in the Hash table
2.Remove item from the Hash Table
3.Display a Hash Table
4.Exit

 Please enter your choice: 4 */
