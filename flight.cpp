//============================================================================
// Name        : assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define inf 9999999
using namespace std;

class node
{
public:

	string vertex2;
	int weight;
	node* next;
	node(string a,int b)
	{
		vertex2=a;
		weight=b;
		next=NULL;
	}

};

class listnode
{
public:

	string vertex1;
	listnode* link_below;
	node* list;
	listnode(string u)
	{
		vertex1=u;
		link_below=NULL;
		list=NULL;
	}
};

class dfs_node
{
	public:
	string u;
	int v;
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
	int n;
	listnode* g;
public:
	graph()
{
	/*	cout<<"Enter number of cities \n";
		cin>>n;
		g=new listnode[n];
		for(int i=0;i<n;i++)
		{
			g[i].list=NULL;
		}
		*/
		n=1;
		g=NULL;
}

		void insertnode(listnode* t, string v,int w)
		{
			if(t->list==NULL)
			{
				t->list=new node(v,w);
			}
			else
			{
				node* p=t->list;
				while(p->next!=NULL)
				{
					p=p->next;
				}
				p->next=new node(v,w);
			}
		}
		void insert_list(string u, string v,int w)
		{
			if(g==NULL)
			{
				g=new listnode(u);
				insertnode(g,v,w);
				return;

			}
			listnode* t=g;
			while(1)
			{
				if(t->vertex1==u)
				{
					insertnode(t,v,w);
					return;
				}
				if(t->link_below!=NULL)
				{
					t=t->link_below;
				}
				else
				{
					t->link_below=new listnode(u);
					t=t->link_below;
					insertnode(t,v,w);
					return;
				}
			}
		}

	/*	void insert(string u, string v,int w)
		{
			int i;
			listnode* t=g;
			node* p;
			for(i=0;i<n;i++)
			{
				if(t[i].list==NULL)
				{
					t[i].vertex1=u;
					t[i].list=new node(v,w);
					return;
				}
				if(t[i].vertex1==u)
				{
					p=t[i].list;
					while(p->next!=NULL)
					{
						p=p->next;
					}
					p->next=new node(v,w);
					return;
				}


			}

		}
	 	 */

		void readgraph()
		{
			int w;
			string u;
			string v;
			while(1)
			{
				cout<<"Enter details of cities and flight \n";
				cout<<"Enter first city or -1 to exit \n";
				cin>>u;
				if(u=="-1")
				{
					break;
				}
				cout<<"Enter second city \n";
				cin>>v;
				cout<<"enter weight \n";
				cin>>w;
				insert_list(u,v,w);
			}
		}

		void display()
		{
			listnode* t=g;
			if(t==NULL)
			{
				cout<<"list is empty \n";
				return;
			}
			node* p;
			cout<<"\n Details are :- \n";
			while(t!=NULL)
			{
				p=t->list;
				cout<<"City "<<t->vertex1<<" is adjacent to :- \n";
				while(p!=NULL)
				{
					cout<<"city "<<p->vertex2<<" and cost is "<<p->weight<<endl;
					p=p->next;
				}
				t=t->link_below;
				cout<<"\n";
			}
		}
		node* delete_node(node* t,string v)
		{
			if(t==NULL)
			{
				return NULL;
			}
			if(t->vertex2==v)
			{
				node* p=t->next;
				delete t;
				return p;
			}
			t->next=delete_node(t->next,v);
			return t;


		}
		void delete_edge(string u, string v)
		{
			listnode* t=g;
			if(t==NULL)
			{
					cout<<"list is empty \n";
					return;
			}
			while(1)
						{
							if(t->vertex1==u)
							{
								t->list=delete_node(t->list,v);
								return;
							}
							if(t->link_below!=NULL)
							{
								t=t->link_below;
							}
							else
							{
								cout<<"Given path between city "<<u<<" and city "<<v<<" is not present in the list \n cannot delete \n";
								return;
							}
						}

		}

		void add_single_vertex(string u)
		{
			if(g==NULL)
			{
				g=new listnode(u);
				cout<<"Given city "<<u<<" is added in the graph \n";
				return;

			}
			listnode* t=g;
						while(1)
						{
							if(t->vertex1==u)
							{
								cout<<"City "<<u<<" is already present in the graph \n cannot add this city \n";
								return;
							}
							if(t->link_below!=NULL)
							{
								t=t->link_below;
							}
							else
							{
								t->link_below=new listnode(u);
								cout<<"Given city "<<u<<" is added in the graph \n";
								return;
							}
						}
		}

		int count_node(node* p)
		{
			int c=0;
			while(p!=NULL)
			{
				p=p->next;
				c++;
			}
			return c;
		}

		void outdegree(string u)
		{
			listnode* t=g;
			int c;
			while(t!=NULL)
			{
				if(t->vertex1==u)
				{
					c=count_node(t->list);
					cout<<"out-degree of city "<<u<<" is "<<c<<endl;
					return;
				}
				else
				{
					t=t->link_below;
				}
			}
			cout<<"given vertex has zero out degree \n";
		}
		
		void indegree(string v)
		{
			listnode* t=g;
			int c=0;
			node* p;
			while(t!=NULL)
			{
				p=t->list;
				while(p!=NULL)
				{
					if(p->vertex2==v)
					{
						c++;
					}
					p=p->next;
				}
				
				t=t->link_below;
				
			}
			cout<<"in-degree of city "<<v<<" is "<<c<<endl;
		}
		
		void dfs(string u,int j,dfs_node* visit)
	{
		for(int i=0;i<j;i++)
		{
			if(visit[i].u==u)
			{
				visit[i].v=1;
				cout<<u<<endl;
				break;
			}
		}
		
		for(int k=0;k<j;k++)
		{
			if(visit[k].v==0)
			{
				dfs(visit[k].u,j,visit);
			}
		}
	}
		
		void traversal()
	{
		string s;
		cout<<"enter source \n";
		cin>>s;
		dfs_node visit[20];
		
		listnode* t=g;
			int i=0;
			int j=0;
			node* p;
			while(t!=NULL)
			{
				for(i=0;i<j;i++)
				{
					if(visit[i].u==t->vertex1)
					{
						break;
					}
				}
				if(i==j)
				{
					visit[i].u=t->vertex1;
					j++;
				}
				
				p=t->list;
				while(p!=NULL)
				{
					for(i=0;i<j;i++)
					{
						if(visit[i].u==p->vertex2)
						{
							break;
						}
					}
					if(i==j)
					{
						visit[i].u=p->vertex2;
						j++;
					}
					p=p->next;
				}
				
				t=t->link_below;
				
			}
		
		for(i=0;i<j;i++)
		{
			if(visit[i].u==s)
			{
				break;
			}
		}
		if(i==j)
		{
			cout<<"invalid source \n";
			return;
		}
		
		cout<<"dfs is \n";
		for(i=0;i<j;i++)
		{
			visit[i].v=0;
		}
		dfs(s,j,visit);
		cout<<"\n";
	}
	
	node* delete_all_nodes(node* p)
	{
		if(p->next==NULL)
		{
			delete p;
			return NULL;
		}
		p->next=delete_all_nodes(p->next);
		return p;
	}
	
	void delete_vertex(string u)
	{
		listnode* t=g;
			int c=0;
			node* p;
			while(t!=NULL)
			{
				t->list=delete_node(t->list,u);
				t=t->link_below;
				
			}
			t=g;
			while(t!=NULL)
			{
				if(t->vertex1==u)
				{
					t->list=delete_all_nodes(t->list);
					break;
				}
				t=t->link_below;
			}
			if(t==NULL)
			{
				return;
			}
			if(t==g)
			{
				g=t->link_below;
				delete t;
				return;
			}
			listnode* q=g;
			while(q->link_below!=t)
			{
				q=q->link_below;
			}
			q->link_below=t->link_below;
			delete t;
			return ;
			
	}
	
	int check(string u, string v)
	{
		listnode* t=g;
		while(t!=NULL)
		{
			if(t->vertex1==u)
			{
				node* p=t->list;
				while(p!=NULL)
				{
					if(p->vertex2==v)
					{
						return p->weight;
					}
				}
				if(p==NULL)
				{
					return inf;
				}
			}
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
		
		listnode* t=g;
			int i=0;
			int j=0;
			node* p;
			while(t!=NULL)
			{
				for(i=0;i<j;i++)
				{
					if(var[i].u==t->vertex1)
					{
						break;
					}
				}
				if(i==j)
				{
					var[i].u=t->vertex1;
					j++;
				}
				
				p=t->list;
				while(p!=NULL)
				{
					for(i=0;i<j;i++)
					{
						if(var[i].u==p->vertex2)
						{
							break;
						}
					}
					if(i==j)
					{
						var[i].u=p->vertex2;
						j++;
					}
					p=p->next;
				}
				
				t=t->link_below;
				
			}
		
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

};

int main()
{
	graph obj;
	string u;
	string v;
	int w;
	int choice;
		int t=2;
		while(t!=3)
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
			cout<<"10. prims \n";
			cout<<"11. to exit \n";
			cin>>choice;
			switch(choice)
			{
				case 1: obj.readgraph();
						break;

				case 2: obj.display();
						break;

				case 3: cout<<"Enter details of cities and flight \n";
						cout<<"Enter first city or -1 to exit \n";
						cin>>u;
						cout<<"Enter second city \n";
										cin>>v;
										cout<<"enter weight \n";
										cin>>w;
										obj.insert_list(u,v,w);
										break;

				case 4: cout<<"Enter details of path between cities you want to delete \n";
				cout<<"Enter first city \n";
				cin>>u;
				cout<<"Enter second city \n";
				cin>>v;
				obj.delete_edge(u,v);
				obj.display();
				break;

				case 5: cout<<"Enter city you want to add \n";
						cin>>u;
						obj.add_single_vertex(u);
						break;

				case 6: cout<<"Enter city to check out-degree \n";
						cin>>u;
						obj.outdegree(u);
						break;
						
				case 7: cout<<"Enter city to check in-degree \n";
						cin>>v;
						obj.indegree(v);
						break;
						
				case 8: obj.traversal();
						break;
						
				case 9: cout<<"enter city you want to delete \n";
						cin>>u;
						obj.delete_vertex(u);
						break;
						
				case 10: obj.prims();
							break;

				case 11: t=3;
						break;
			}
		}
}

