#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i;
    cin >> n >> k;
    string s;
    cin >> s;
    unordered_set<char> st;
    for (i = 0; i < k; i++)
    {
        char ch;
        cin >> ch;
        st.insert(ch);
    }

    vector<int> bin(n);
    for (i = 0; i < n; i++)
    {
        if (st.find(s[i]) != st.end())
        {
            bin[i] = 1;
        }
        else
        {
            bin[i] = 0;
        }
    }
    long long ct = 0, tot = 0;

    for (i = 0; i < n; i++)
    {
        if (bin[i] == 1)
        {
            ct++;
        }
        else
        {
            tot += ct * (ct + 1) / 2;
            ct = 0;
        }
    }
    tot += ct * (ct + 1) / 2;

    cout << tot;
}