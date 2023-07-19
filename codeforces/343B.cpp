#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    stack<char> st;

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }

    if (st.empty())
        cout << "Yes";
    else
        cout << "No";
}