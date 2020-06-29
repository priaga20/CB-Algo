//Check if a linked list is a palindrome.( Boolean return type )

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

node* findMid(node* head)
{
    node *s=head,*f=head->next;
    while(f!=NULL && f->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
    }
    return s;
}

node* reverseLL(node* head)
{
    node *curr=head,*prev=NULL,*nex=head;
    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}

bool checkPalindrome(node* head)
{
    if(head==NULL || head->next==NULL)
        return true;

    //reversing second half of LL
    node* mid=findMid(head);
    node* temp=head;
    mid->next=reverseLL(mid->next);

    while(mid->next!=NULL)
    {
        if(temp->data!=mid->next->data)
            return false;
        else
        {
            mid=mid->next;
            temp=temp->next;
        }
    }
    return true;
}

//can be done using stack also
bool palindrome(node* head)
{
    if(head==NULL)
    {
        return false;
    }
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    stack<node*> s;
    node* ptr=head;
    while(ptr!=slow)
    {
        s.push(ptr);
        ptr=ptr->next;
    }
    if(fast!=NULL)
    {
        slow=slow->next;
    }
    while(slow!=NULL)
    {
        node* temp=s.top();
        s.pop();
        if(temp->data!=slow->data)
        {
            return false;
        }
        slow=slow->next;
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        insert_end(head,tail,data);
    }
    bool ans=checkPalindrome(head);
    if(ans)
        cout<<"True";
    else
        cout<<"False";
    return 0;
}