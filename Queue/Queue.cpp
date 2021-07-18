#include<iostream>
using namespace std;
#define n 20

class queue
{
    int* arr;
    int front;
    int back;

    public:

    queue()
    {
        arr= new int[n];
        front=-1;
        back=-1;
    }
    void push(int x)
    {
        if(back==n-1)
        {
            cout<<"Queue has overflowed\n";
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1) front++;
    }
    void pop()
    {
        if(front==-1 || front>back)
        {
            cout<<"Queue is empty\n";
            return;
        }
        front++;
    }
    int peek()
    {
        if(front==-1 || front>back)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        return (front==-1 || front>back);
    }
    void display()
    {
        if(front==-1 || front>back)
        {
            cout<<"Queue is empty\n";
            return;
        }
        for(int i=front; i<=back; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    cout<<boolalpha<<q.empty()<<endl;
    cout<<q.peek()<<endl;
    q.display();


}