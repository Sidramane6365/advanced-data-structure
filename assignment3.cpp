//============================================================================
// Name        : assignment3.cpp
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
	int data;
	node *left,*right;
	int lbit,rbit;
	int child;
	node(int x)
	{
		data=x;
		left=right=NULL;
		lbit=rbit=1;
	}
};
class tbt
{
	node *root;
public:
	tbt()
	{
		root=new node(-1);
		root->left=root->right=root;
	}
	void create()
	{
		create_rec(root,0);
	}
	void create_rec(node *father,int child)
	{
		int x;
		cout<<"Enter data or -1 to stop"<<endl;
		cin>>x;
		if(x==-1)
		{
			return;
		}
		node *t=new node(x);
		if(child==0)
		{
			t->child=child;
			t->right=father;
			t->left=father->left;
			father->left=t;
			father->lbit=0;
		}
		else
		{

			t->child=child;
			t->left=father;
			t->right=father->right;
			father->right=t;
			father->rbit=0;
		}
		cout<<"Enter left of "<<x<<endl;
			create_rec(t,0);
			cout<<"Enter right of "<<x<<endl;
				create_rec(t,1);
	}
	void preorder()
	{
		cout<<"preorder expression is "<<endl;;
		node *t=root->left;
		while(t!=root)
		{
			cout<<t->data<<" ";
			t=pre_succ(t);
		}
		cout<<endl;
	}
	node* pre_succ(node *t)
	{
		if(t->lbit==0)
			return t->left;
		if(t->rbit==0)
			return t->right;
		while(t->rbit==1 && t!=root)
		{
			t=t->right;
		}
		return t->right;
	}
	void inorder()
	{
		cout<<"inorder expression is "<<endl;;
				node *t=root->left;
				while(t->lbit==0)
					t=t->left;
				while(t!=root)
				{
					cout<<t->data<<" ";
					t=in_succ(t);
				}
				cout<<endl;
	}
	node* in_succ(node *t)
	{
		if(t->rbit==1)
		{
			return t->right;
		}
		if(t->rbit==0)
			t=t->right;
		while(t->lbit==0)
		{
			t=t->left;
		}
		return t;
	}
		void del(int x)
		{
			cout<<"hello"<<endl;
			root->left=del_rec(root->left,x);
		}
		node* del_rec(node *t,int x)
		{
			if(t==root)
			{
				cout<<"Not found"<<endl;
				return t;
			}
			if(x<t->data)
			{
				t->left=del_rec(t->left,x);
				return t;
			}
			else if(x>t->data)
			{
				t->right=del_rec(t->right,x);
				return t;
			}
			if(t->lbit==1 && t->rbit==1)
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
			if(t->rbit==1)
			{
				node *p=t->left;
				delete t;
				return p;
			}
			node* p=findmin(t->right);
			t->data=p->data;
			t->right=del_rec(t->right,t->data);
			return t;
		}
		node* findmin(node *t)
			{
				while(t->left!=NULL)
				{
					t=t->left;
				}
				return t;
			}
};
int main()
{
	int x;
	tbt obj;
	obj.create();
	obj.preorder();
	obj.inorder();
	cout<<"Enter data to delete "<<endl;
	cin>>x;
	obj.del(x);
	obj.inorder();
	return 0;
}
