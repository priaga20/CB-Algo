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

void kFromLast(node* &head,int k)
{
    if(head==NULL)
        return;
    //using pointer runner technique
    node* f=head;
    node* s=head;
    for(int i=0;i<k;i++)
    {
        f=f->next;
    }
    while(f!=NULL)
    {
        s=s->next;
        f=f->next;
    }
    cout<<s->data;
}
   
int main() 
{
    node* head=NULL;
    node* tail=NULL;
    int data;
    cin>>data;
    while(data!=-1)
    { 
        insert_end(head,tail,data);
        int t;
        cin>>t;
        data=t;
    }
    int k;
    cin>>k;
    kFromLast(head,k);
}