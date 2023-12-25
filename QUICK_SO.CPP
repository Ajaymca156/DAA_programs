#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class QUICKSORT
{
	int n,*A;
	public:
		QUICKSORT(int);
		void SET_LIST();
		void GET_LIST();
		void QUICK_SORT(int,int);
		void PARTITION(int,int &);
};
QUICKSORT::QUICKSORT(int para)
{
	n=para;
	A=new int[n+1];
}
void QUICKSORT::SET_LIST()
{
	for(int i=1;i<=n;i++)
		A[i]=random(5000);
}
void QUICKSORT::GET_LIST()
{
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
}
void QUICKSORT::PARTITION(int m,int &p)
{
	int v = A[m];
	int i = m;
	do
	{
		do
			i++;
		while(v>A[i]);
		do
			p--;
		while(v<A[p]);
		if(i<p)
		{
			int t=A[i];
			A[i]=A[p];
			A[p]=t;
		}
		else
			break;
	}while(1);
	A[m]=A[p];
	A[p]=v;

}
void QUICKSORT::QUICK_SORT(int p,int q)
{
	if(p<q)
	{
		int j=q+1;
		PARTITION(p,j);
		QUICK_SORT(p,j-1);
		QUICK_SORT(j+1,q);
	}
}
void main()
{
	int n;
	clrscr();
	cout<<"Enter the no of LIST :- ";
	cin>>n;
	QUICKSORT obj(n);
	obj.SET_LIST();
	cout<<"\nList before sorting :- ";
	obj.GET_LIST();
	obj.QUICK_SORT(1,n);
	cout<<"\nList after sorting :- ";
	obj.GET_LIST();
	getch();
}