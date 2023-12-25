#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int n,i=1;
	cout<<"Enter the no of * in pattern: ";
	cin>>n;
	cout<<"Given star pattern is "<<n<<"*"<<n<<"\n";
	while(i<=n)
	{
		int j=1;
		while(j<=n)
		{
			cout<<"*";
			j++;
		}
		cout<<"\n";
		i++;
	}
	getch();
#include<iostream.h>
#include<conio.h>
class HEAP
{
	int n, A[100];
	public:
		HEAP(int);
		void SET_LIST();
		void GET_LIST();
		void INSERT(int);
};
HEAP::HEAP(int par)
{
	n = par;
}
void HEAP::SET_LIST()
{
	cout<<"Enter the list elements :- ";
	for(int i=1;i<=n;i++)
		cin>>A[i];
}
void HEAP::GET_LIST()
{
	cout<<"\nThe list elements are :- ";
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
}
void HEAP::INSERT(int no)
{
	int i,j;
	j = no;
	i = no/2;
	int item = A[no];
	while(i>0 && A[i]<item)
	{
		A[j] = A[i];
		j = i;
		i = i/2;
	}
	A[j]=item;
}
void main()
{
	clrscr();
	int n;
	cout<<"Enter the no of elements in the LIST :- ";
	cin>>n;
	HEAP obj(n);
	obj.SET_LIST();
	obj.GET_LIST();
	for(int i=2;i<=n;i++)
		obj.INSERT(i);
	cout<<"\nLIST after insert : - ";
	obj.GET_LIST();
	getch();
}