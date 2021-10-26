#include<bits/stdc++.h>
using namespace std;

void solve(long long n,long long x,long long t)
{
    if(x > t)
    {
        cout<<0<<endl;
        return;
    }
    if(x == t)
    {
        cout<<n-1<<endl;
        return;
    }
    else
    {
        long long f = t/x;
        long long k = f+1;
        if(n >= k) cout<<k*(k-1)/2 + (n-k)*f <<endl;
        else cout<<n*(n-1)/2<<endl;
        return;
    }
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,x,t;
        cin>>n>>x>>t;
        solve(n,x,t);
    }
}