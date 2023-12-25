#include<iostream.h>
#include<conio.h>
class HEAP
{
	int n, A[100];
	public:
		HEAP(int);
		void SET_LIST();
		void GET_LIST();
		void HEAPIFY(int);
		void ADJUST(int);
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
void HEAP::ADJUST(int i)
{
	int j,item;
	j = 2*i;
	item = A[i];
	while(j<=n)
	{
		if(j<n && A[j] < A[j+1])
			j = j+1;
		if(A[j]<=item)
			break;
		else
		{
			A[j/2]=A[j];
			j=j*2;
		}
	}
	A[j/2]=item;
}
void HEAP::HEAPIFY(int n)
{
	for(int i=n/2;i>=1;i--)
		ADJUST(i);
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
	obj.HEAPIFY(n);
	cout<<"\nLIST after adjust : - ";
	obj.GET_LIST();
	getch();
}