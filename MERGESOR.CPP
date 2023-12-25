#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class MERGESORT
{
	int n,*A;
	public:
		MERGESORT(int);
		void SET_LIST();
		void GET_LIST();
		void MERGE(int,int,int);
		void MERGE_SORT(int,int);
};
MERGESORT::MERGESORT(int para)
{
	n=para;
	A=new int[n+1];
}
void MERGESORT::SET_LIST()
{
	for(int i=1;i<=n;i++)
		A[i]=random(5000);
}
void MERGESORT::GET_LIST()
{
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
}
void MERGESORT::MERGE(int mid,int low,int high)
{
	int i=low;
	int h=low;
	int *B=new int[n+1];
	int j=mid+1;
	while(h<=mid&&j<=high)
	{
		if(A[h]<A[j])
		{
			B[i]=A[h];
			h++;
		}
		else
		{
			B[i]=A[j];
			j++;
		}
		i++;
	}
	if(h>mid)
	{
		for(int k=j;k<=high;k++)
		{
			B[i]=A[k];
			i++;
		}
	}
	else
	{
		for(int k=h;k<=mid;k++)
		{
			B[i]=A[k];
			i++;
		}
	}
	for(int k=low;k<=high;k++)
		A[k]=B[k];
	delete B;
}
void MERGESORT::MERGE_SORT(int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MERGE_SORT(low,mid);
		MERGE_SORT(mid+1,high);
		MERGE(mid,low,high);
	}
}
void main()
{
	int n;
	clrscr();
	cout<<"Enter the no of LIST :- ";
	cin>>n;
	MERGESORT obj(n);
	obj.SET_LIST();
	cout<<"\nList before sorting :- ";
	obj.GET_LIST();
	obj.MERGE_SORT(1,n);
	cout<<"\nList after sorting :- ";
	obj.GET_LIST();
	getch();
}