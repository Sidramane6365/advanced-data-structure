//============================================================================
// Name        : assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#define inf 1000 
using namespace std;
class pnode
{
public:
	string adjcity;
	float time;
	pnode *next;
	pnode(string c,float t)
	{
		adjcity=c;
		time=t;
		next=NULL;
	}
};
class cnode
{
public:
	string city;
	pnode *head;
	cnode *down;
	cnode(string c)
	{
		city=c;
		head=NULL;
		down=NULL;
	}
};
class prims_node
{
	public:
	string u;
	int visited;
	int dist;
	string from;
};

class graph
{
	cnode *g;
public:
	graph()
	{
		g=NULL;
	}
	void create()
	{
		string x,y;
		float t;
		while(1)
		{
			cout<<"Enter city or -1 to stop"<<endl;
			cin>>x;
			if(x=="-1")
			{
				break;
		}
			while(1)
			{
				cout<<"Enter city to which have line from "<<x<<" or -1 to stop "<<endl;
				cin>>y;
				if(y=="-1")
				{
					break;
				}
				cout<<"Enter amount of money required to line from "<<x<<" to "<<y<<endl;
				cin>>t;
				insertlist(x,y,t);
				insertlist(y,x,t);
			}
		}
	}
	void insertlist(string x,string y,float t)
	{
		cnode *p;
		if(g==NULL)
		{
			g=new cnode(x);
			insertnode(g,y,t);
		}
		else
		{
			p=g;
			while(1)
			{
				if(p->city==x)
				{
					insertnode(p,y,t);
					break;
				}
				if(p->down!=NULL)
				{
					p=p->down;
				}
				else
				{
					p->down=new cnode(x);
					p=p->down;
					insertnode(p,y,t);
					break;
				}
			}

		}
	}
	void insertnode(cnode *g,string y,float t)
	{
		if(g->head==NULL)
		{
			g->head=new pnode(y,t);
		}
		else
		{
			pnode *p;
			p=g->head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new pnode(y,t);
		}
	}
	void show()
	{
		cnode *p=g;
		while(p!=NULL)
		{
			cout<<"city "<<p->city<<" : ";
			pnode *q=p->head;
			while(q!=NULL)
			{
				cout<<q->adjcity<<",";
				q=q->next;
			}
			cout<<endl;
			p=p->down;
		}
	}
	int check(string u, string v)
	{
		
		cnode* t=g;
		while(t!=NULL)
		{
			if(t->city==u)
			{
				pnode* p=t->head;
				while(p!=NULL)
				{
					if(p->adjcity==v)
					{
						return p->time;
					}
					p=p->next;
				}
				if(p==NULL)
				{
					return inf;
				}
			}
			t=t->down;
		}
		if(t==NULL)
		{
			return inf;
		}
	}
	
	void prims()
	{
	    
		string s;
		cout<<"enter source \n";
		cin>>s;
		prims_node var[20];
		int j=0;
		
		visited(g,var,j);
		
		int i;
		
		for(i=0;i<j;i++)
		{
			if(var[i].u==s)
			{
				var[i].visited=1;
				break;
			}
		}
		if(i==j)
		{
			cout<<"invalid source \n";
			return;
		}
		
	
		for(i=0;i<j;i++)
		{
		
			if(var[i].u!=s)
			{
			var[i].visited=0;
			var[i].dist=check(s,var[i].u);
			var[i].from=s;
			}
			else
			{
			     var[i].visited=1;
			}
			
		}
			
		int k=j-1;
		string v1;
		string u1;
		cout<<"Traversal is :- \n";
		int mindist,mincost=0;
		while(k>0)
	{
		mindist=inf;
		for(i=0;i<j;i++)
		{
			if(var[i].visited==0 && var[i].dist<mindist)
			{
				mindist=var[i].dist;
				v1=var[i].u;
				
			}
		}
		
		for(i=0;i<j;i++)
		{
			if(var[i].u==v1)
			{
				u1=var[i].from;
				var[i].visited=1;
				break;
			}
		}
		
		cout<<u1<<"->"<<v1<<"\t is visited \n";
		mincost=mincost+check(u1,v1);
		for(i=0;i<j;i++)
		{
			if(var[i].visited==0 && check(v1,var[i].u)<var[i].dist)
			{
				var[i].dist=check(v1,var[i].u);
				var[i].from=v1;
				
			}
		}
		k--;
	}
	cout<<"min cost is "<<mincost<<endl;
	}
     void visited(cnode *t,prims_node *var,int &j)
     {
          
			int i=0;
		
			pnode* p;
			while(t!=NULL)
			{
				for(i=0;i<j;i++)
				{
					if(var[i].u==t->city)
					{
						break;
					}
				}
				if(i==j)
				{
					var[i].u=t->city;
					j++;
				}
				
				p=t->head;
				while(p!=NULL)
				{
					for(i=0;i<j;i++)
					{
						if(var[i].u==p->adjcity)
						{
							break;
						}
					}
					if(i==j)
					{
						var[i].u=p->adjcity;
						j++;
					}
					p=p->next;
				}
				
				t=t->down;
				
			}
     }
};
int main()
 {
	graph obj;
	int choice;
	string x,y;
	float t;
	while(1)
	{
			cout<<"1. Create Graph \n";
			cout<<"2. Display Graph \n";
			cout<<"3. minimum cost\n";
			cout<<"4. to exit \n";
			cin>>choice;
			switch(choice)
			{
				case 1:
				{
					obj.create();
					break;
				}
				case 2:
				{
					obj.show();
					break;
				}
				case 3:
				{
				     obj.prims();
				     break;
				}
				
				case 4:
				{
					exit(1);
				}
			}


	}
	return 0;
}
