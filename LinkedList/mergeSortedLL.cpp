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

node* mergeLists(node* head1,node* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    node* head=NULL;
    if(head1->data<head2->data)
    {
        head=head1;
        head->next=mergeLists(head1->next,head2);
    }
    else
    {
        head=head2;
        head->next=mergeLists(head1,head2->next);
    }
    return head;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        node* head1=NULL;
        node* tail1=NULL;
        node* head2=NULL;
        node* tail2=NULL;
        int n1,n2;
        cin>>n1;
        for(int i=0;i<n1;i++)
        {
            int data;
            cin>>data;
            insert_end(head1,tail1,data);
        }
        cin>>n2;
        for(int i=0;i<n2;i++)
        {
            int data;
            cin>>data;
            insert_end(head2,tail2,data);
        }
        node* head=mergeLists(head1,head2);
        printLL(head);
    }
}