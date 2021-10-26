// https://codeforces.com/problemset/problem/1598/A
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s1;
    string s2;

    cin>>s1>>s2;

    for(int i=0; i<n ; i++)
    {
        if(s1[i] == '1' && s2[i] == '1')
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}