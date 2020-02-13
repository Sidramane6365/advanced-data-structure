//============================================================================
// Name        : assignment6.cpp
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
	string key,val;

};
class dict
{
	node obj[20];
	int n;
public:

	void create()
	{
		n=0;
		string x,y;

			cout<<"Enter key "<<endl;
			cin>>x;
			cout<<"Enter value"<<endl;
			cin>>y;
			obj[n].key=x;
			obj[n].val=y;
			n++;
			while(1)
			{
			cout<<"Enter key or -1 to stop"<<endl;
			cin>>x;
			if(x=="-1")
				break;
			cout<<"Enter value"<<endl;
			cin>>y;
			insert(x,y);
		}
	}
	void insert(string x,string y)
	{

		int i=0;
		cout<<"hi"<<endl;

			while(obj[i].key<x && i<n)
			{
				cout<<"hi1"<<endl;
				i++;
			}
			cout<<"hi2"<<endl;
			obj[i].key=x;
			obj[i].val=y;
			n++;
		}

	void display()
	{
		for(int i=0;i<n;i++)
		{
			cout<<obj[i].key<<" :  "<<obj[i].val<<endl;
		}
	}
};


int main()
{
	dict obj;
	//obj.create();
	//obj.display();

//	obj.display();


	return 0;
}
