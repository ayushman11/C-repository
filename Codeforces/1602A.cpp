// https://codeforces.com/problemset/problem/1602/A
#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    string a = "";
    string b = "";
    char min_c= 'z';

    for(int i=0; i<s.length(); i++)
    {
        if (s[i] < min_c)
        {
            min_c = s[i];
        }
    }

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == min_c) {
            a += min_c;
            min_c='\0';
        }
        else
        {
            b += s[i];
        }
    }

    cout<<a<<" "<<b<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
    }
}