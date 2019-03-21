#include<iostream>
#define ll long long
using namespace std;
int a[100][100];
	int visited[100];
	int path[100];
	int path2[100];
	int top=-1;
	int top2;
	int flag;
	int stack[100];
ll n,k;
void dfs(int in);
int main()
{ll t,i,q,j,a2,b;
	cin>>t;
	
	for(i=0;i<t;i++)
	{top=-1;
		cin>>n>>q;
		flag=0;
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			a[j][k]=0;
		}
		for(j=0;j<q;j++)
		{
			cin>>a2>>b;
			a[a2][b]=1;
		}
		for(j=0;j<n;j++)
		{
		    stack[j]=0;
		visited[j]=0;
		}
		
		for(j=0;j<n;j++)
		{
		  if(visited[j]==0)
		  {
		  	dfs(j);
		  }	
		}
		if(flag==0)
		cout<<"-1\n";
		else
		{
		  for(j=0;j<=top2;j++)
		  cout<<path2[j]<<" ";	
		  cout<<"\n";
		}		
		
	}
}
void dfs(int in)
{int i,j;
	visited[in]=1;
	stack[in]=1;
	path[++top]=in;
	for(i=0;i<n;i++)
	{
			if(a[in][i]==1&&visited[i]==0)
			{
				dfs(i);
			}
			else if(a[in][i]==1&&stack[i]==1&&flag==0)
			{
				path[++top]=i;
				top2=top;
				for(j=0;j<=top;j++)
				{
					path2[j]=path[j];
				}
				flag=1;
				break;
			}
	}
	--top;
	stack[in]=0;
}
