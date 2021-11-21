#include <bits/stdc++.h>
using namespace std;

// O(nlogn)

int main()
{
    int n,k;
    cin>>n>>k;

    vector <int> a(n);

    for(auto &i : a) 
    {
        cin>>i;
    }

    multiset <int, greater <int>> s;
    vector <int> ans;

    for(int i=0; i<k; i++)
    {
        s.insert(a[i]);
    }

    ans.push_back(*s.begin());

    for(int i=k; i<n; i++)
    {
        s.erase(s.lower_bound(a[i-k])); // to delete only one element equal to a[i-k]. If used s.erase(a[i-k]), all elements equal to a[i-k] will get erased
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }

    for(auto i: ans) cout<<i<<" ";

    cout<<endl;
}