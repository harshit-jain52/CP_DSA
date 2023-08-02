#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int n;
    cin >> n;
    int a[n], x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x = x ^ a[i];
    }

    if (x == 0)
        return true;

    bool isPresent = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            isPresent = true;
            a[i] = 0;
            break;
        }
    }
    if (!isPresent)
        return false;

    set<int> st;
    st.insert(0);
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        y = y ^ a[i];

        if (st.find(y ^ x) != st.end())
            return true;

        st.insert(y);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool ans = solve();
        if (ans)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
}