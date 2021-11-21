#include <bits/stdc++.h>
using namespace std;

int get_max_area(vector <int> a)
{
    stack <int> st;
    int ans =0;
    int n = a.size();

    for(int i=0; i<n; i++)
    {
        while(!st.empty() and a[st.top()] > a[i])
        {
            int t = st.top();
            int h = a[t];
            st.pop();
            if(st.empty())
            {
                ans = max(ans, h*i);
            }
            else
            {
                int len = i - st.top() - 1; // extra -1 because we have already popped the top element
                ans = max(ans, h*len);
            }
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector <int> a = {2,1,5,6,2,3};
    cout<<get_max_area(a);
}