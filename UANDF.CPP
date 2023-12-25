#include"iostream.h"
#include"conio.h"
class SET
{
	int n,PAR[20];
	public:
		SET(int);
		void SHOW();
		void UNION(int,int);
		int FIND(int);
		void MENU();
};
SET::SET(int par)
{
	n = par;
	for(int i=1;i<=n;i++)
		PAR[i]=-1;
}
void SET::SHOW()
{
	cout<<"\n\tNODE\tPARENT";
	for(int i=1;i<=n;i++)
		cout<<"\n"<<"\t"<<i<<"\t"<<PAR[i];
}
void SET::UNION(int i,int j)
{
	if(PAR[i]==-1&&PAR[j]==-1)
	{
		int x = PAR[i]+PAR[j];
		if(PAR[i]>PAR[j])
		{
			PAR[i]=j;
			PAR[j]=x;
		}
		else
		{
			PAR[j]=i;
			PAR[i]=x;
		}
	}
	else
		cout<<"\nEnter the valid nodes!!!";
}
int SET::FIND(int i)
{
	int k,j;
	j=k=i;
	while(PAR[j]>-1)
		j=PAR[j];
	while(PAR[k]!=j)
	{
		int t=PAR[k];
		PAR[k]=j;
		k=t;
	}
	return k;
}
void SET::MENU()
{
	int i,j,opt;
	do
	{
		cout<<"\n________MENU_______";
		cout<<"\n1::UNION";
		cout<<"\n2::FIND";
		cout<<"\n3::EXIT";
		cout<<"\n___________________";
		cout<<"\nEnter option :- ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\nEnter the nodes :- ";
				cin>>i>>j;
				if(i!=j)
				{
					UNION(i,j);
					SHOW();
				}
				else
					cout<<"\nEnter the valid nodes!!!";
				break;
			case 2:
				cout<<"\nEnter the node to find :- ";
				cin>>i;
				FIND(i);
				SHOW();
				break;
			case 3:
				return;
			default:
				cout<<"\nEnter the valid option___!!!!";
		}

	}while(1);
}
void main()
{
	int n;
	clrscr();
	cout<<"Enter the total nodes :- ";
	cin>>n;
	SET obj(n);
	obj.MENU();
	getch();
}