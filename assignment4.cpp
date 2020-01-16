//============================================================================
// Name        : assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class pnode
{
public:
	string cit;
	int v;
	float time;
	pnode *next;
	pnode(string c,int u,float t)
	{
		cit=c;
		v=u;
		time=t;
		next=NULL;
	}
};
class cnode
{
public:
	string city;
	int v;
	pnode *head;
	cnode *down;
	cnode(string c,int u)
	{
		city=c;
		v=u;
		head=NULL;
		down=NULL;
	}
};
class graph
{
	cnode *g;
public:
	void create()
	{
		cnode *p;
		string x;
		cout<<"Enter city or -1 to stop"<<endl;
		cin>>x;
		g=new cnode(x,0);
		p=g;
		int i=1;
		while(1)
		{
			cout<<"Enter next city or -1 to stop"<<endl;
			cin>>x;
			if(x=="-1")
				break;
			p->down=new cnode(x,i);
			p=p->down;
			i++;
		}
	}
	void show()
	{
		cnode *p;
		p=g;
		while(p!=NULL)
		{
			cout<<p->city<<endl;
			p=p->down;
		}
	}
	void path()
	{
		string x,y;
		cnode* v;
		pnode *p;
		float t;
		while(1)
		{
		cout<<"Enter two cities having path or -1 to stop"<<endl;
		cin>>x;
		if(x=="-1")
			break;
		cin>>y;
		cout<<"Enter time required to travel"<<endl;
		cin>>t;
		v=findindex(x);
		if(v->head==NULL)
		v->head=new pnode(y,0,t);
		else
			{
			int i=0;
				p=v->head;
				while(p!=NULL)
				{
					p=p->next;
					i++;
				}
				p->next=new pnode(y,i,t);
			}
		}

	}
	cnode* findindex(string x)
	{
		cnode *p;
				p=g;
				while(p!=NULL)
				{
					if(p->city==x)
						return p;
					p=p->down;
				}
				cout<<"city not found"<<endl;
				return NULL;
	}
};
int main() {
	graph obj;
	obj.create();
	obj.show();
	return 0;
}
