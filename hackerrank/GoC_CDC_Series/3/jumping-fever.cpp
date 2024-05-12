#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll c[n];
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1)
    {
        cout << c[0];
        return 0;
    }

    set<pair<ll, int>> st;
    st.insert({c[0], min(n - 1, a[0])});

    for (int i = 1; i < n; i++)
    {
        while ((*st.begin()).second < i)
            st.erase(st.begin());
        ll mincost = c[i] + (*st.begin()).first;
        if (i == n - 1)
        {
            cout << mincost;
            return 0;
        }
        st.insert({mincost, min(n - 1, i + a[i])});
    }
}