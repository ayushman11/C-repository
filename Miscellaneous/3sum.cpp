#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int target;
    cin>>target;

    int a[n];
    for(auto &i: a) cin>>i;

    sort(a, a+n); // nlogn

    for(int i=0; i<n; i++)
    {
        int lo=i+1, hi = n-1;

        while(lo<hi)
        {
            int curr = a[i] + a[lo] + a[hi];

            if(curr == target)
            {
                cout<<"True\n";
                return 0;
            }
            else if(curr < target)
            {
                lo++;
            }
            else 
            {
                hi--;
            }
        }
    }
    cout<<"False\n";
    return 0;
}