//============================================================================
// Name        : assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
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
				cout<<"Enter city to which flight available from "<<x<<" or -1 to stop "<<endl;
				cin>>y;
				if(y=="-1")
				{
					break;
				}
				cout<<"Enter time required to travel from "<<x<<" to "<<y<<endl;
				cin>>t;
				insertlist(x,y,t);
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
	
	void deledge(string x,string y)
	{
		pnode *r;
		cnode *p=g;
		while(p->city!=x)
		{
			p=p->down;
		}
		p->head=delnode(p->head,y);
	}
	pnode* delnode(pnode *t,string y)
	{
		if(t==NULL)
		{
			return NULL;
		}
		if(t->adjcity==y)
		{
			pnode *p=t->next;
			delete t;
			return p;
		}
		t->next=delnode(t->next,y);
		return t;
	} 
	void add_single_vertex(string u)
		{
			if(g==NULL)
			{
				g=new cnode(u);
				cout<<"Given city "<<u<<" is added in the graph \n";
				return;

			}
			cnode* t=g;
						while(1)
						{
							if(t->city==u)
							{
								cout<<"City "<<u<<" is already present in the graph \n cannot add this city \n";
								return;
							}
							if(t->down!=NULL)
							{
								t=t->down;
							}
							else
							{
								t->down=new cnode(u);
								cout<<"Given city "<<u<<" is added in the graph \n";
								return;
							}
						}
		}
		int count_node(pnode* p)
		{
			int c=0;
			while(p!=NULL)
			{
				p=p->next;
				c++;
			}
			return c;
		}

		void outdegree()
		{
			cnode* t=g;
			int c;
			while(t!=NULL)
			{
				
					c=count_node(t->head);
					cout<<"out-degree "<<t->city<<" : "<<c<<endl;
					t=t->down;
				
			}
			
		}
		
		void indegree(string v)
		{
			cnode* t=g;
			int c=0;
			pnode* p;
			while(t!=NULL)
			{
				p=t->head;
				while(p!=NULL)
				{
					if(p->adjcity==v)
					{
						c++;
					}
					p=p->next;
				}
				
				t=t->down;
				
			}
			cout<<"in-degree of city "<<v<<" is "<<c<<endl;
		}
		void delete_vertex(string u)
		{
			cnode* t=g;
			cnode* p=g;
			int c=0;
			
			while(t!=NULL)
			{
				t->head=delnode(t->head,u);
				t=t->down;
				
			}
			t=g;
			while(t!=NULL)
			{
				if(t->city==u)
				{
					
					t->head=delete_all_nodes(t->head);
					break;
				}
				t=t->down;
			}
			if(t==NULL)
			{
				return ;
			}
			else
			{
				while(p->down!=t)
				{
					p=p->down;
				}
				p->down=t->down;
				delete t;

			}
			
		}
		pnode* delete_all_nodes(pnode* p)
		{
			if(p->next==NULL)
			{
				delete p;
				return NULL;
			}
			p->next=delete_all_nodes(p->next);
			return p;
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
			cout<<"3. Add single path between two cities \n";
			cout<<"4. Delete a path between two cities\n";
			cout<<"5. Add a  single city in list \n";
			cout<<"6. Display Out-degree of a vertex \n";
			cout<<"7. Display In-degree of a vertex \n";
			cout<<"8. dfs \n"; 
			cout<<"9. delete single city(vertex) \n";
			cout<<"10. to exit \n";
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
			
					cout<<"Enter details of cities and flight \n";
					cout<<"Enter first city or -1 to exit \n";
					cin>>x;
					cout<<"Enter second city \n";
					cin>>y;
					cout<<"Enter time required to travel"<<endl;
					cin>>t;						
					obj.insertlist(x,y,t);
					obj.show();
					break;
				}
				case 4:
				{
					cout<<"Enter details of cities and flight \n";
					cout<<"Enter first city or -1 to exit \n";
					cin>>x;
					cout<<"Enter second city \n";
					cin>>y;
					obj.deledge(x,y);
					obj.show();
					break;	
				}
				case 5:
				{ 
						cout<<"Enter city you want to add \n";
						cin>>x;
						obj.add_single_vertex(x);
						obj.show();
						break;
				}
				case 6:
				{
						obj.outdegree();
						break;
				}
						
				case 7: 
				{
						cout<<"Enter city to check in-degree \n";
						cin>>x;
						obj.indegree(x);
						break;
				}
				case 9:
				{
					cout<<"enter city you want to delete \n";
					cin>>x;
					obj.delete_vertex(x);
					break;
				}
				case 10:
				{
					exit(1);
				}
			}
		
	
	}
	return 0;
}
