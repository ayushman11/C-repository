#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int idx=s.length();
        while(idx > 0 ) {
            for(int i=0; i<idx-1; i++) {
                if(s[i]>s[i+1]) swap(s[i], s[i+1]);
            }
            idx--;
        } 
        cout<<s<<endl;
    }
}