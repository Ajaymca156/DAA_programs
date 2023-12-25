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
		void MAX_MIN(int,int,int&,int&);
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
void LIST::MAX_MIN(int i,int j,int &fmax,int &fmin)
{
	int gmax,gmin,hmax,hmin;
	if(i==j)
		fmax=fmin=A[i];
	else
	{
		if(i==j-1)
		{
			if(A[i]>A[j])
			{
				fmax=A[i];
				fmin=A[j];
			}
			else
			{
				fmax=A[j];
				fmin=A[i];
			}
		}
		else
		{
			int mid = (i+j)/2;
			MAX_MIN(i,mid,gmax,gmin);
			MAX_MIN(mid+1,j,hmax,hmin);
			if(gmax>hmax)
				fmax=gmax;
			else
				fmax=hmax;
			if(gmin<hmin)
				fmin=gmin;
			else
				fmin=hmin;
		}
	}
}
void main()
{
	clrscr();
	int ch,fmax,fmin;
	cout<<"Enter the no of LIST :- ";
	cin>>ch;
	LIST obj(ch);
	obj.SET_LIST();
	cout<<"\nLIST elements are :- ";
	obj.GET_LIST();
	obj.MAX_MIN(1,ch,fmax,fmin);
	cout<<"\n\tMAXIMUM\tMINIMUM";
	cout<<"\n\t"<<fmax<<"\t"<<fmin;
	getch();
}