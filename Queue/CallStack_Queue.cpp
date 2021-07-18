#include<bits/stdc++.h>
using namespace std;

class queues
{
    stack<int> s1;
    public:
    void push(int val)
    {
        s1.push(val);
    }
    int pop()
    {
        if(s1.empty())
        {
            cout<<"Queue is empty\n";
            exit(0);
        }
        int x=s1.top();
        s1.pop();
        if(s1.empty()) return x;
        int item=pop();
        s1.push(x);
        return item;        
    }
    /*We store the top of stack in each call in x, until we reach the last elemrnt. We return the last element which is stored in item. 
    As we come back to previous calls, we push back the elements stored in x, and continue returning item(last ele) which ultimately
    returns from overall pop function. This way we remove the bottom-most element without disturbing order. */
    bool empty()
    {
        return (s1.empty());
    }
};

int main()
{
    queues q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty();
}