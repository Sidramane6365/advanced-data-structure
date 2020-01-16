//============================================================================
// Name        : assignment1.cpp
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

	node(int x)
	{
		data=x;
		left=right=NULL;
	}
	~ node()
	{
		cout<<"node deleted"<<endl;
	}
	friend class tree;
};
class stacknode
{
public:
	node *link;
	int flag;
};
template<class T>
class stack
{
	T data1[30];
	int top;
public:
	stack()
	{
		top=-1;
	}
	void push(T x)
	{
		top++;
		data1[top]=x;
	}
	T pop()
	{
		if(!empty())
		{
			 T x=data1[top];
			top--;
			return x;
		}
		T y;
		return y;

	}
	int empty()
	{
		if(top==-1)
		{
			return 1;
		}
		return 0;
	}
};
class tree
{
	node *root;
public:
	tree()
	{
		root=NULL;
	}
	void  create();
	node* create_rec();
	void show();
	void postorder(node *t);
	void preorder(node *t);
	void inorder(node *t);
	void mir(tree&);
	node* mirror_rec(node *);
	void operator =(tree);
	node * cop(node *);
	void count();
	int count_rec(node *t);
	int count_rec1(node *t);
	void del();
	void delrec(node *);
	int inter(node*);
	void nonrec_preorder();
	void nonrec_inorder();
	void nonrec_postorder();
	void shownon();
	node* mirror_rec1(node *t);
	bool check(tree obj);
	bool checkrec(node *t,node *p);

};
void tree:: create()
{
	root=create_rec();
}
node* tree:: create_rec()
{
	int x;
	node *t;
	cout<<"Enter data or -1 to stop "<<endl;
	cin>>x;
	if(x!=-1)
	{
		t=new node(x);
		cout<<"Enter left of "<<x<<endl;
		t->left=create_rec();
		cout<<"Enter right of "<<x<<endl;
		t->right=create_rec();
		return t;
	}
	else
	{
		return NULL;
	}

}
void tree::show()
{
	if(root==NULL)
	{
		cout<<"tree is empty"<<endl;
	}
	else
	{
	cout<<"postorder expression is"<<endl;
	postorder(root);
	cout<<endl;
	cout<<"preorder expression is"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"inorder expression is"<<endl;
	inorder(root);
	cout<<endl;
	}
}
void tree::shownon()
{

	cout<<"postorder expression is"<<endl;
	nonrec_postorder();
	cout<<endl;
	cout<<"preorder expression is"<<endl;
	nonrec_preorder();
	cout<<endl;
	cout<<"inorder expression is"<<endl;
	nonrec_inorder();
	cout<<endl;

}
void tree::postorder(node *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout<<t->data<<" ";
	}
}
void tree::preorder(node *t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		preorder(t->left);
		preorder(t->right);

	}
}
void tree::inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);

	}
}
void tree::nonrec_preorder()
	{
		stack<node *>s;
		node *t=root;
		while(t!=NULL)
		{
			cout<<t->data<<" ";
			s.push(t);
			t=t->left;
		}
		while(!s.empty())
		{
			t=s.pop();
			t=t->right;
			while(t!=NULL)
			{
				cout<<t->data<<" ";
				s.push(t);
				t=t->left;
			}
		}
		cout<<endl;
	}
	void tree::nonrec_inorder()
	{
		stack<node *>s;
				node *t=root;
				while(t!=NULL)
				{

					s.push(t);
					t=t->left;
				}
				while(!s.empty())
				{
					t=s.pop();
					cout<<t->data<<" ";
					t=t->right;
					while(t!=NULL)
					{

						s.push(t);
						t=t->left;
					}
				}
				cout<<endl;
	}
	void tree::nonrec_postorder()
	{
		stack<stacknode>s;
		node *t=root;
		stacknode obj;
		while(t!=NULL)
		{
			obj.link=t;
			obj.flag=1;
			s.push(obj);
			t=t->left;
		}
		while(!s.empty())
		{
			obj=s.pop();
			t=obj.link;
			if(obj.flag==1)
			{
				obj.flag=2;
				s.push(obj);
				t=t->right;
			while(t!=NULL)
			{
				obj.link=t;
				obj.flag=1;
				s.push(obj);
				t=t->left;
			}
			}
			else
			{
				cout<<t->data<<" ";
			}
		}
		cout<<endl;
	}
void tree::operator =(tree obj)
{

	root=cop(obj.root);

}
node * tree::cop(node *t)
{
	node *p;
		if(t!=NULL)
		{

				p=new node(t->data);
				p->right=cop(t->right);
				p->left=cop(t->left);
				return p;
		}
		return t;
}
node* tree::mirror_rec1(node *t)
{
	node *p;
	if(t!=NULL)
	{

			p=new node(t->data);
			p->left=mirror_rec1(t->left);
			p->right=mirror_rec1(t->right);
			return p;
	}
	return t;
}
void tree::mir(tree &obj)
{
	obj.root=mirror_rec(root);

}
node* tree::mirror_rec(node *t)
{
	node *p;
	if(t!=NULL)
	{

			p=new node(t->data);
			p->left=mirror_rec(t->right);
			p->right=mirror_rec(t->left);
			return p;
	}
	return t;
}

void tree::count()
{
	int l,i;
	int c=count_rec(root);
	cout<<"total nodes present in tree are "<<c<<endl;
	cout<<"leaf nodes are"<<endl;
	i=count_rec1(root);
	cout<<endl;
	cout<<"count of leaf nodes is "<<i<<endl;
	cout<<"internal nodes are"<<endl;
	l=inter(root);
	cout<<endl;
	cout<<"count of internal nodes is "<<l<<endl;


}
int tree::inter(node *t)
{


	if(t!=NULL)
		{

			if((t->left!=NULL || t->right!=NULL) && t!=root)
			{
				cout<<t->data<<" ";
				return 1+inter(t->left)+inter(t->right);
			}

			else
			{
				return inter(t->left)+inter(t->right);
			}


		}
		return 0;
}
int tree::count_rec(node *t)
{
	if(t!=NULL)
	{
		return 1+count_rec(t->left)+count_rec(t->right);

	}
	return 0;
}
int tree::count_rec1(node *t)
{
	if(t!=NULL)
	{
		int l=count_rec1(t->left);
		int r=count_rec1(t->right);
		if(l+r==0)
		{
			cout<<t->data<<" ";
			return 1;
		}
		else
		{
			return l+r;
		}


	}
	return 0;
}
void tree::del()
{
	delrec(root);
	root=NULL;
}
	void tree::delrec(node *t)
	{
			if(t!=NULL)
			{
				delrec(t->left);
				delrec(t->right);
				delete t;
			}

	}
bool tree::check(tree obj)
{
			if(checkrec(root, obj.root))
			{

				return true;
			}
			else
			{

				return false;

			}
}
bool tree::checkrec(node *root1,node *root2)
{
			bool l,r;
			if(root1 != NULL && root2 !=NULL)
			{
				l = checkrec(root1->left, root2->left);
				r = checkrec(root1->right, root2->right);
				if(l== true && r == true)
				{
					if(root1->data == root2->data)
						return true;
					else
						return false;


				}
				else
					return false;
			}
			else
			{
				if(root1 == NULL && root2 == NULL)
					return true;
				else
					return false;
			}
}
int main()
{
	int x=1,z;
	tree obj,mi,obj1,obj2;
	obj.create();
	while(x)
	{
	cout<<"Enter 1 for copy \n2 for Delete all nodes \n3 for mirror \n4 for check equal or not \n5 for show \n6. print internal and leaf nodes"<<endl;
	cin>>x;

	switch(x)
	{
			case 1:
			{
				obj1=obj;
				cout<<"another tree is created"<<endl;
				obj1.show();
				break;
			}
			case 2:
			{
				obj.del();
				obj.show();
				break;
			}
			case 3:
			{
				obj.mir(mi);
				cout<<"mirror image of tree is created"<<endl;
				mi.show();
				break;
			}
			case 4:
			{
				cout<<"create a tree which you want to check equal or not"<<endl;
				obj2.create();
				cout<<"new tree is"<<endl;
				obj2.show();
				if(obj.check(obj2))
				{
					cout<<"both trees are equal"<<endl;
				}
				else
				{
					cout<<"both trees are not equal"<<endl;
				}
				break;
			}
			case 5:
			{
				cout<<"Enter 1 for recursive and 2 for non-recursive"<<endl;
				cin>>z;
				if(z==1)
				obj.show();
				else
					obj.shownon();
				break;
			}
			case 6:
			{
				obj.count();
				break;
			}

	}
	cout<<"Enter 1 to continue or 0 to stop"<<endl;
	cin>>x;

	}

	return 0;
}
