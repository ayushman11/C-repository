#include<bits/stdc++.h>
using namespace std;

class queues
{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int val)
    {
        s1.push(val);
    }
    int pop()
    {
        if(s1.empty() and s2.empty())
        {
            cout<<"Queue is empty\n";
            exit(0);
        }
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval=s2.top();
        s2.pop();
        return topval;
    }
    bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};
/*All the push go to s1 stack, and when a pop is called we check if s2 is empty. If empty, we pop and push each element from s1 to s2,
thus reversing order. Now when we pop from s2, it's actually the bottom-most element that would have been in s1. If not empty, we simply
pop from s2. Push is always done to s1.*/

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