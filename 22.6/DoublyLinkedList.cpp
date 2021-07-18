#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
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
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void insertAtHead(node* &head, int val)
{
    node* n= new node(val);
    if(head!=NULL)
    {
        head->prev=n;
    }
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
        head->prev=NULL;
        delete todelete;
        return;
    }
    while(temp->next->data!=k)
    temp=temp->next;
    node* todelete= temp->next;
    temp->next=todelete->next;
    if(todelete->next!=NULL)todelete->next->prev=temp;
    delete todelete;
}

int main()
{
    node* head= NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,0);
    display(head);
    deletion(head,0);
    display(head);
    deletion(head,4);
    display(head);
}