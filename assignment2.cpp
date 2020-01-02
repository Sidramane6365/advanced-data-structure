//============================================================================
// Name        : assignment2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node
{
public:
	string word,mean;
	node *left,*right;
	node(string x,string y)
	{
		word=x;
		mean=y;
		left=right=NULL;
	}
};
class dict
{
	node *root;
	public:
	dict()
	{
		root=NULL;
	}
	void create();
	node* insert(node*,string,string);
	void show(int x);
	void inorder_rec(node *);
	void desc_rec(node *);
	void add(string x);
	node* findmin(node *t);
	void del(string x);
	node* del_rec(node *t,string x);
	void up_mean(string x,string y,string z);
	void up_word(string x,string y);
	node* copy(node *);
	void operator =(dict obj);
	void up_mean(string x,string y);
	node* change_mean(node *t,string x,string y);
	int comparision(string x);
	int comp(node *t,string x);

};
	void dict::create()
	{
		string x;
		string y;
		while(1)
		{
			cout<<"Enter word or -1 to stop"<<endl;
			cin>>x;
			if(x=="-1")
			{
				break;
			}
			cout<<"Enter meaning"<<endl;
			cin>>y;
			root=insert(root,x,y);
		}
	}
	void dict::add(string x)
	{
		string y;
		cout<<"Enter meaning of "<<x<<endl;
		cin>>y;


			root=insert(root,x,y);

	}
	node* dict::insert(node *t,string x,string y)
	{
		if(t==NULL)
		{
			t=new node(x,y);
			return t;
		}
			if(x<t->word)
			{
				t->left=insert(t->left,x,y);
				return t;
			}
			else if(x>t->word)
			{
				t->right=insert(t->right,x,y);
				return t;
			}
			else
			{
				cout<<"duplicate element can't add"<<endl;
				return t;
			}
	}
	void dict::show(int x)
	{
		cout<<"dictionary is "<<endl;
		if(x==0)
		{
		inorder_rec(root);
		cout<<endl;
		}
		else
		{
			desc_rec(root);
			cout<<endl;
		}
	}
	void dict::inorder_rec(node *p)
	{
		if(p!=NULL)
		{
			inorder_rec(p->left);
			cout<<p->word<<": "<<p->mean;
			cout<<endl;
			inorder_rec(p->right);

		}
	}
	void dict::desc_rec(node *p)
		{
			if(p!=NULL)
			{
				desc_rec(p->right);
				cout<<p->word<<": "<<p->mean;
				cout<<endl;
				desc_rec(p->left);

			}
		}
	void dict::del(string x)
	{
		root=del_rec(root,x);
	}
	node* dict::del_rec(node *t,string x)
	{
		if(t==NULL)
		{
			cout<<"Not found"<<endl;
			return NULL;
		}
		if(x<t->word)
		{
			t->left=del_rec(t->left,x);
			return t;
		}
		if(x>t->word)
		{
			t->right=del_rec(t->right,x);
			return t;
		}
		if(t->left==NULL && t->right==NULL)
		{
			delete t;
			return NULL;
		}
		if(t->left==NULL)
		{
			node *p=t->right;
			delete t;
			return p;
		}
		if(t->right==NULL)
		{
			node *p=t->left;
			delete t;
			return p;
		}
		node* p=findmin(t->right);
		t->word=p->word;
		t->right=del_rec(t->right,t->word);
		return t;
	}
	node* dict::findmin(node *t)
	{
		while(t->left!=NULL)
		{
			t=t->left;
		}
		return t;
	}
	void dict::up_word(string x,string y)
	{
		del(x);
		add(y);
	}
	void dict::operator =(dict obj)
	{

		root=copy(obj.root);

	}
	node * dict::copy(node *t)
	{
		node *p;
			if(t!=NULL)
			{

					p=new node(t->word,t->mean);
					p->right=copy(t->right);
					p->left=copy(t->left);
					return p;
			}
			return t;
	}
	void dict::up_mean(string x,string y)
	{
		root=change_mean(root,x,y);
	}
	node* dict::change_mean(node *t,string x,string y)
	{
		if(t!=NULL)
		{
			if(x<t->word)
			{
				t->left=change_mean(t->left,x,y);
				return t;
			}
			else if(x<t->word)
			{
				t->right=change_mean(t->right,x,y);
				return t;
			}
			else
			{
				t->mean=y;
				return t;
			}


		}
		cout<<"not found"<<endl;
		return t;
	}
	int dict::comparision(string x)
		{
			return comp(root,x);
		}
	int dict::comp(node *t,string x)
	{

		if(t!=NULL)
		{
			if(x<t->word)
			{
				return 1+comp(t->left,x);

			}
			else if(x<t->word)
			{
			return 1+comp(t->right,x);

			}
			else
			{
				return 1;
			}


		}

		return 0;
	}
int main()
{
	string x,y,z;
	dict obj,obj1;
	cout<<"Enter a dictionary"<<endl;
	cout<<endl;
	obj.create();
	obj.show(0);
	int a=1;
	int b;
	while(a)
	{
	cout<<"Enter\n 1: add new word\n 2: Delete word\n 3: update keyword\n 4: update meaning\n 5: Display ascending\n 6: Display Descending"<<endl;
	cout<<" 7:copy dictionary\n 8:find comparisions to search word\n"<<endl;
	cin>>b;
	switch(b)
	{
	case 1:
	{
		cout<<"Enter keyword to add"<<endl;
		cin>>x;
		obj.add(x);
		obj.show(0);
		break;
	}
	case 2:
	{
		cout<<"Enter keyword to delete"<<endl;
		cin>>x;
		obj.del(x);
		obj.show(0);
		break;
	}
	case 3:
	{
		cout<<"Enter keyword to update"<<endl;
		cin>>x;
		cout<<"Enter keyword by which "<<x <<"should update"<<endl;
		cin>>y;
		obj.up_word(x,y);
		obj.show(0);
		break;
	}
	case 4:
	{
		cout<<"Enter keyword whose meaning to update"<<endl;
		cin>>x;
		cout<<"Enter meaning"<<endl;
		cin>>y;
		obj.up_mean(x,y);
		obj.show(0);
		break;
	}
	case 5:
		{
			obj.show(0);
			break;
		}
	case 6:
		{
			obj.show(1);
			break;
		}
	case 7:
	{
		obj1=obj;
		cout<<"new dictionary is created"<<endl;
		obj.show(0);
		break;
	}
	case 8:
	{
		cout<<"Enter keyword to calculate comparisions"<<endl;
		cin>>x;
		cout<<"comparisions required for "<<x<<" are "<<obj.comparision(x)<<endl;
		break;
	}
	}
	cout<<"Enter 1 to continue and 0 to stop"<<endl;
	cin>>a;
	}

	return 0;


}
