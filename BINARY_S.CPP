#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class LIST
{
	int n,*A;
	public:
		LIST(int);
		void SET_LIST();
		void GET_LIST();
		void SORT();
		void BINARY_SEARCH(int,int&);
};
LIST::LIST(int par)
{
	n = par;
	A = new int[n+1];
}
void LIST::SET_LIST()
{
	for(int i=1; i<=n; i++)
		A[i]=random(5000);
}
void LIST::GET_LIST()
{
	for(int i=1; i<=n; i++)
		cout<<A[i]<<" ";
}
void LIST::BINARY_SEARCH(int x, int &j)
{
	int low,high,mid;
	low=1;
	high=n;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(x==A[mid])
		{
			j=mid;
			return;
		}
		else if(x<A[mid])
			high=mid-1;
		else
			low=mid+1;
	}j=0;
}
void LIST::SORT()
{
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-i;j++)
		{
			if(A[j]>A[j+1])
			{
				int t = A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
}
void main()
{
	clrscr();
	int ch,x,pos;
	cout<<"Enter the no of LIST :- ";
	cin>>ch;
	LIST obj(ch);
	obj.SET_LIST();
	cout<<"\nLIST before SORTING :- ";
	obj.GET_LIST();
	obj.SORT();
	cout<<"\nLIST after SORTING :- ";
	obj.GET_LIST();
	cout<<"\nEnter the element need to find :- ";
	cin>>x;
	obj.BINARY_SEARCH(x,pos);
	if(pos)
		cout<<"\nElement found at "<<pos<<" position in the list.";
	else
		cout<<"\nElement is not found !!!!";
	getch();
}