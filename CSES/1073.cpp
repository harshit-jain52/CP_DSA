#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    int k[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    multiset<int> st;
    int ct = 0;

    for (int i = 0; i < n; i++)
    {
        auto it = st.upper_bound(k[i]);
        if (it == st.end())
            ct++;
        else
            st.erase(it);

        st.insert(k[i]);
    }

    cout << ct;
}