#include <iostream>
#include<climits>
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

void insertInSortedLL(node* &sortedHead, node* newNode)
{
	if(sortedHead==NULL || newNode->val < sortedHead->val)
	{
		newNode->next=sortedHead;
		sortedHead=newNode;
	}
	else
	{
		node* curr=sortedHead;
		while(curr->next!=NULL && curr->next->val < newNode->val)
		{
			curr= curr->next;
		}
		newNode->next=curr->next;
		curr->next=newNode;
	}
}

void sortLL(node* &head)
{
	if(head==NULL || head->next==NULL)
		return;

	node* sortedHead=NULL;
	node* curr=head;
	while(curr!=NULL)
	{
		node* nex=curr->next;
		insertInSortedLL(sortedHead,curr);
		curr=nex;
	}
	head=sortedHead;
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
	sortLL(head);
	printLL(head);
	return 0;
}