//============================================================================
// Name        : assignment5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
# define inf 1000

class graph
{
public:
	int **g,cost[20][20];
	int visited[10],dist[10],from[10];
	int u,v,w,i,j,ne;
	int n;
		graph()
	{
			cout<<"Enter no of vertices"<<endl;
			cin>>n;
			g=new int*[n];
			for(int i=0;i<n;i++)
			{
				g[i]=new int[n];
			}
	}
	void readgraph()
		{
		cout<<"Enter adjacency matrix"<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cin>>g[i][j];
				}
			}
		}
	void findcost()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(g[i][j]==0)
				{
					cost[i][j]=inf;
				}
				else
				{
					cost[i][j]=g[i][j];
				}
			}
		}

	}
	void findmin()
	{
		int mincost,min=0;
		visited[0]=1;
		for(int i=1;i<n;i++)
		{
			visited[i]=0;
			dist[i]=cost[0][i];
			from[i]=0;
		}
		ne=n-1;
		while(ne>0)
		{
			mincost=inf;
			for(int i=0;i<n;i++)
			{
				if(dist[i]<mincost && visited[i]==0)
				{
					mincost=dist[i];
					v=i;
				}
			}
			visited[v]=1;
			u=from[v];
			cout<<u<<" "<<v<<" Added"<<endl;
			mincost=cost[u][v];
			min=min+mincost;
			for(int i=0;i<n;i++)
			{
				if(visited[i]==0 && dist[i]>cost[v][i])
				{
					dist[i]=cost[v][i];
					from[i]=v;
				}
			}
			ne--;
		}
		cout<<"min cost is"<<min<<endl;
	}
};
int main() {
	graph obj;
	obj.readgraph();
	obj.findcost();
	obj.findmin();
	return 0;
}
