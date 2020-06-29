#include <iostream>
using namespace std;

class node{
	public:
	
	int val;
	node* next;

	node(int val)
	{
		this->val = val;
		next=NULL;
	}
};

void insert_end(node* &head,node* &tail,int val)
{
    if(head==NULL)
    {
        node* p=new node(val);
        head=p;
        tail=p;
    }
    else
    {
        node* p=new node(val);
        tail->next=p;
        tail=tail->next;
    }
}

void evenAfterOdd(node* &head)
{
	if(head==NULL || head->next==NULL)
		return;

	node *headOdd=NULL, *headEven=NULL;
	node *tailOdd=NULL, *tailEven=NULL;

	node *p=head;
	while(p!=NULL)
	{
		if( (p->val & 1) == 1)	//odd value
		{
			if(headOdd==NULL)
				headOdd=p;
			else
				tailOdd->next=p;

			tailOdd=p;
		}
		else
		{
			if(headEven==NULL)
				headEven=p;
			else
				tailEven->next=p;

			tailEven=p;
		}
		p=p->next;
	}

	if(headEven==NULL)
		head=headOdd;

	else if(headOdd==NULL)
	{
		tailEven->next=NULL;
		head=headEven;
	}
	
	else
	{
		tailEven->next=NULL;
		tailOdd->next=headEven;
		head=headOdd;
	}
}

void printLL(node *head)
{
	node* p=head;
	while(p!=NULL)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
}

int main(int argc, char const *argv[])
{
	node *head=NULL, *tail=NULL;
	int n;
	cin>>n;
	while(n--)
	{
		int val;
		cin>>val;
		insert_end(head,tail,val);
	}
	evenAfterOdd(head);
	printLL(head);
	return 0;
}