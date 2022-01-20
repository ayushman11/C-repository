#include <bits/stdc++.h>
using namespace std;

void solve(int n,int m,int r,int c) {
    r-=1;
    c-=1;
    char a[n+1][m+1];
    bool hasB= false;
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>a[i][j];
            if(a[i][j] == 'B') hasB=true;
        }
    }
    if(!hasB) {
        cout<<-1<<endl;
        return;
    }

    if(a[r][c] == 'B') {
        cout<<0<<endl;
        return;
    }

    bool isPresent= false;
    for(int i=0; i<m; i++) {
        if(a[r][i] == 'B') isPresent=true;
    }
    for(int j=0; j<n; j++) {
        if(a[j][c] == 'B') isPresent= true;
    }

    if(isPresent) {
        cout<<1<<endl;
        return;
    } else {
        cout<<2<<endl;
        return;
    }

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        solve(n,m,r,c);
    }
}