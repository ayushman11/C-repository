#include <bits/stdc++.h>
using namespace std;

string decToBin(int n)
{
    if(n == 0) return "";
    string ans = decToBin(n/2);
    if(n%2 == 0) return ans + "0";
    else return ans + "1";
}

int binToDec(string s)
{
    int x = 1;
    int ans=0;
    for(int i=s.length()-1 ; i>=0; i--) {
        if(s[i]=='0') ans += 0;
        else ans += x;

        x*=2;
    }

    return ans;
}

void solve(int n, int l) {
    string ans="";
    int count[l];
    memset(count,0,sizeof(count));

    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        string s = decToBin(k);
        if(s.length() < l) {
            int diff = l-s.length();
            string start = string(diff, '0');
            s = start + s;
        }
        // cout<<s<<" ";
        for(int j=0; j<l ;j++) {
            if(s[j] == '1') count[j]++;
        }
    }

    for(int i=0; i<l; i++) {
        if(count[i] > n/2) ans+= "1";
        else ans+="0";
    }

    // cout<<ans<<" ";

    cout<<binToDec(ans)<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,l;
        cin>>n>>l;
        solve(n,l);
    }
}