#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class queue {
    public:

    node* front;
    node* back;

    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        node* n = new node(x);
        if(front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;        
    }

    void peek()
    {
        if(front == NULL)
        {
            cout<<"NO element to peek"<<endl;
        }

        cout<<front->data<<endl;
    }

    void pop()
    {
        if(front == NULL)
        {
            cout<<"NO element to pop"<<endl;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    bool empty()
    {
        return front == NULL;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.peek();
    q.pop();
    q.peek();
    q.pop();
    q.peek();
    q.pop();
    q.peek();
    q.pop();

    cout<<q.empty();
}