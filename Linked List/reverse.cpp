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

node* reverse(node* &head)
{
    node* prev = NULL;
    node* curr = head;
    node* next;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev= curr;
        curr = next; 
    }

    return prev; // because it points at new head now
}

node* recursiveReverse(node* &head)
{
    if(head == NULL || head->next == NULL) return head;

    node* newhead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    // node* temp = newhead;
    // while(temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = head;
    // head->next = NULL;

    return newhead;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    
    node* newhead = recursiveReverse(head);
    display(newhead);

}