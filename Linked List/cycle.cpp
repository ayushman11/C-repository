#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
    return;
}

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;

    while(temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next = n;
    return;
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
    return;
}

bool detectCycle(node* &head)
{
    node* fast= head;
    node* slow= head;

    while(fast != NULL && fast->next != NULL)
    {
        slow= slow->next;
        fast= fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

void makeCycle(node* &head, int pos)
{
    node* joinNode;
    node* temp = head;

    int count=0;
    while(temp->next != NULL)
    {
        if(count == pos)
        {
            joinNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next=joinNode;
}

void removeCycle(node* &head)
{
    node* slow= head;
    node* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while(slow->next != fast->next)
    {
        slow= slow->next;
        fast= fast->next;
    }
    slow->next = NULL;
    
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);

    makeCycle(head,2);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    display(head);
    cout<<detectCycle(head)<<endl;
}