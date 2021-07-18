#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    node* next;
    int data;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, int val)
{
    node* n= new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=n;
}
void insertAtHead(node* &head, int val)
{
    node* n= new node(val);
    n->next=head;
    head=n;
}
void display(node* head)
{
    while(head != NULL) {
    cout<<head->data<<"->";
    head=head->next;
    }
    cout<<"NULL"<<endl;

}
void deletion(node* &head, int k)
{
    node* temp=head;
    if(head->data==k)
    {
        node* todelete= head;
        head= head->next;
        delete todelete;
        return;
    }
    while(temp->next->data!=k)
    temp=temp->next;
    node* todelete= temp->next;
    temp->next=todelete->next;
    delete todelete;
}

int main()
{
 
}