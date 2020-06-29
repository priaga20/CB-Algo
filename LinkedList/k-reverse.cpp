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

//using iteration
void kReverseIte(node* &head,int k)
{
    if(head==NULL || head->next==NULL)
        return;
    
    node *kPtr=head, *prev=NULL, *curr=head, *temp=kPtr, *nex=NULL;
    int flag=0;
    for(int i=0;i<k-1;i++)
    {
        if(kPtr->next!=NULL)
            kPtr=kPtr->next;
    }
    while(kPtr!=NULL)
    {
        //reverse k nodes
        nex=curr;
        prev=kPtr->next;
        node* p=kPtr->next;
        while(curr!=p)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        if(!flag)  //head updated only once
        {
            head=prev;
            flag=1;
        }
        kPtr=temp->next;
        if(kPtr!=NULL)
        {
            for(int i=0;i<k-1;i++)
            {
                if(kPtr->next!=NULL)
                    kPtr=kPtr->next;
            }
            temp->next=kPtr;
            temp=curr;
        }
    }
}

//using recursion
node* kReverse(node* head,int k)
{
    if(head==NULL || head->next==NULL)
        return head;

    int count=k;
    node* n=head;
    node* c=head;
    node* p=NULL;
    while(count>0 && c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        count--;
    }
    head->next=kReverse(c,k);
    return prev;
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

int main() {
    int n,k;
    cin>>n>>k;
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        insert_end(head,tail,data);
    }
    head=kReverse(head,k);
    printLL(head);
}