#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;
    int len = s.length();
    int n;
    cin >> n;
    int solve[len];
    memset(solve, 0, sizeof(solve));
    int roll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> roll[i];
        solve[roll[i] - 1]++;
    }

    int current = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (solve[i] != 0)
            current += solve[i];
        s[i] += current;
        if (s[i] > 122)
            s[i] = s[i] - 122 + 96;
    }

    cout << s << endl;
}