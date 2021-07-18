#include<bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack <int> &st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    InsertAtBottom(st,ele);
    st.push(topele);
}

void reverse(stack <int> &st)
{
    if(st.empty())
    {
        return;
    }
    int ele=st.top();
    st.pop();
    reverse(st);
    InsertAtBottom(st,ele);
}
int main()
{
    stack <int> st;
    for(int i=0; i<5; i++)st.push(i+1);
    reverse(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}