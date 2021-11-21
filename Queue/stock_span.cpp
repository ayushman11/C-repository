#include <bits/stdc++.h>
using namespace std;

vector <int> stock_span(vector <int> a)
{
    vector <int> ans;
    stack <pair<int,int>> st;

    for(int i=0; i<a.size(); i++)
    {
        int days = 1;
        while(!st.empty() and st.top().first < a[i])
        {
            days += st.top().second;
            st.pop();
        }
        ans.push_back(days);
        st.push({a[i], days});
    }
    return ans;
}

int main()
{
    vector <int> a = {100, 80, 60, 70, 60, 75, 85};
    vector <int> ans = stock_span(a);

    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
}