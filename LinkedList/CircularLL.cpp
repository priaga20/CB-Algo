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

bool insert_end(node* &head,node* &tail,int val)
{
    if(head==NULL)
    {
        node* p=new node(val);
        head=p;
        tail=p;
    }
    else
    {
    	//check if already exists
    	node *temp=head;
    	while(temp!=NULL)
    	{
    		if(temp->val==val){
    			tail->next=temp;
    			return true;
    		}
    		temp=temp->next;
    	}
    	//node does not exists already
        node* p=new node(val);
        tail->next=p;
        tail=tail->next;
    }
    return false;
}

node* detectCycle(node* head)
{
	node *a=head,*b=head;
	a=a->next;
	b=b->next->next;
	while(a!=b)
	{
		a=a->next;
		b=b->next->next;
	}
	a=head;
	while(a!=b)
	{
		a=a->next;
		b=b->next;
	}
	return a;
}

void removeCycle(node* &head)
{
	if(head==NULL || head->next==NULL)
		return;
	node *c=detectCycle(head);
	if(c==NULL)  //cycle not there
		return;
	node *p=c->next;
	while(p->next!=c)
	{
		p=p->next;
	}
	p->next=NULL;
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

	int v;
	cin>>v;
	while(v!=-1)
	{
		bool isPresent=insert_end(head,tail,v);
		//curr v is already present 
		//nodes will start repeating after this 
		if(isPresent)
			break;
		cin>>v;
	}
	removeCycle(head);
	printLL(head);
	return 0;
}