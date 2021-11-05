#include <bits/stdc++.h>
using namespace std;

void reverseString(string str)
{
    stringstream s(str);
    string word;
    stack <string> st;

    while(s >> word) st.push(word);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    string s = "Hello, how are you doing?";
    reverseString(s);
}