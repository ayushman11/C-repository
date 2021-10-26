#include<bits/stdc++.h>
using namespace std;

void solve(long n, long a, long b, long counter)
{
    if(b >= 0) cout<<n*(a+b)<<endl;
    else
    {
        if(counter == 1 || counter == 2) cout<<n*a+counter*b<<endl;
        else cout<<n*a + (ceil(counter/2) + 1)*b <<endl;
    }
}

long main()
{
    long t;
    cin>>t;
    while(t--)
    {
        long n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        long counter=1;
        for(long i=0; i<s.length()-1; i++)
        {
            if(s[i] != s[i+1]) counter++;
        }
        solve(n,a,b,counter);
    }
}
