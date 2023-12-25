#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class HEAP
{
	int n,*A;
	public:
		HEAP(int);
		void SET_LIST();
		void GET_LIST();
		void HEAP_SORT();
		void HEAPIFY();
		void ADJUST(int,int);
};
HEAP::HEAP(int para)
{
	n=para;
	A = new int[n+1];
}
void HEAP::SET_LIST()
{
	for(int i=1;i<=n;i++)
		A[i]=random(5000);
}
void HEAP::GET_LIST()
{
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
}
void HEAP::HEAP_SORT()
{
	HEAPIFY();
	for(int i=n;i>1;i--)
	{
		int t=A[i];
		A[i]=A[1];
		A[1]=t;
		ADJUST(1,i-1);
	}
}
void HEAP::HEAPIFY()
{
	for(int i=n/2;i>=1;i--)
		ADJUST(i,n);
}
void HEAP::ADJUST(int i,int n)
{
	int j,item;
	j=2*i;
	item=A[i];
	while(j<=n)
	{
		if(j<n && A[j]<A[j+1])
			j=j+1;
		if(A[j]<=item)
			break;
		else
		{
			A[j/2]=A[j];
			j=j*2;
		}
	}A[j/2]=item;
}
void main()
{
	int n;
	clrscr();
	cout<<"Enter the no of list :- ";
	cin>>n;
	HEAP obj(n);
	obj.SET_LIST();
	cout<<"\nList elements are :- ";
	obj.GET_LIST();
	obj.HEAP_SORT();
	cout<<"\nList after Sorting :- ";
	obj.GET_LIST();
	getch();
}