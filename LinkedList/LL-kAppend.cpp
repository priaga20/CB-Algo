#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void insert_end(node* &head,node* &tail,int data)
{
    if(head==NULL)
    {
        node* p=new node(data);
        head=p;
        tail=p;
    }
    else
    {
        node* p=new node(data);
        tail->next=p;
        tail=tail->next;
    }
}

void printLL(node *head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void reverseLL(node* &head)
{
    node* curr=head;
    node* prev=NULL;
    node* nex=curr;
    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    head=prev;
}

void kAppend(node* &head,int k,int n)
{
    if(head==NULL)
    {
        return;
    }
    //using runner pointer technique
    node* temp=head;
    node* f=head;
    node* s=head;
    for(int i=0;i<k;i++)
    {
        f=f->next;
    }
    while(f->next!=NULL)
    {
        s=s->next;
        f=f->next;
    }
    f->next=temp;
    head=s->next;
    s->next=NULL;
}

int main() {
    int n,k;
    cin>>n;
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        insert_end(head,tail,data);
    }
    cin>>k;
    //imp step as k can be > n
	k=k%n;
    kAppend(head,k,n);
    printLL(head);
}