#include<bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    if(s.length()==0) return "";
    char x=s[0];
    string res=reverse(s.substr(1));
    res+=x;
    return res;
}
int precedence(char c)
{
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string infixToPrefix(string s)
{
    string revs=reverse(s);
    for(int i=0; i<revs.length(); i++)
    {
        if(revs[i]=='(') revs[i]=')';
        else if(revs[i]==')') revs[i]='(';
    }
    string res="";
    stack<char> st;
    for(int i=0; i<revs.length(); i++)
    {
        if(revs[i]>='a'&&revs[i]<='z' || revs[i]>='A'&&revs[i]<='Z') res+=revs[i];
        else if(revs[i]=='(') st.push(revs[i]);
        
        else if(revs[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }
        else 
        {
            while (!st.empty() && precedence(st.top())>precedence(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(revs[i]);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return reverse(res);
}

int main()
{
    string s="(a-b/c)*(a/k-l)";
    cout<<infixToPrefix(s);
}