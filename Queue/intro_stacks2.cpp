#include <bits/stdc++.h>
using namespace std;

class que {
    stack <int> s1;

    public:

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if(s1.empty())
        {
            cout<<"No element in Queue\n";
            return -1;
        }

        int topval = s1.top();
        s1.pop();
        if(s1.empty())
        {
            return topval;
        }

        int bottom_val = pop();
        s1.push(topval);

        return bottom_val;
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    que q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    q.push(5);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty();
}