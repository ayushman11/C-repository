#include <bits/stdc++.h>
using namespace std;

bool redundant_paranthesis(string s)
{
    stack <char> st;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
        {
            st.push(s[i]);
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(st.top() == '(')
            {
                return true;
            }
            while(st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/')
            {
                st.pop();
            }
            st.pop();
        }
    }
    return false;
}

int main()
{
    string s;
    cin>>s;
    cout<<redundant_paranthesis(s);
}