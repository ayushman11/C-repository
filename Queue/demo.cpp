#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll N=1000000007;
    ll n;
    cin>>n;
    ll sum=0;

    for(ll i=0; i<n; i++)
    {
        ll k;
        cin>>k;
        sum=(sum+k+N)%N;
    }
    ll q;
    cin>>q;
    while(q--)
    {
        sum=(sum*2)%N;
        cout<<sum<<endl;
    }
}