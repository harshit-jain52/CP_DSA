#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    ll a[n];
    a[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }

    ll tot = n * (n + 1) / 2, sum = a[n - 1];
    if (sum > tot)
    {
        cout << "NO";
        return;
    }

    unordered_map<ll, int> m;
    for (int i = 1; i < n; i++)
    {
        ll diff = a[i] - a[i - 1];
        m[diff]++;
    }

    if (sum < tot)
    {
        if (m.size() == n - 1 && m.find(sum - tot) == m.end())
            cout << "YES";

        else
            cout << "NO";

        return;
    }

    // tot=sum

    if (m.size() == n - 2)
    {
        int num;
        for (auto it : m)
        {
            if (it.second == 2)
            {
                num = it.first;
                break;
            }
        }

        for (int i = 1; i < num; i++)
        {
            if (m.find(i) == m.end() && m.find(num - i) == m.end())
            {
                cout << "YES";
                return;
            }
        }
    }
    if (m.size() == n - 1)
    {
        int num;
        int ct = 0;
        for (auto it : m)
        {
            if (it.first > n)
            {
                num = it.first;
                ct++;
            }
        }

        if (ct != 1)
        {
            cout << "NO";
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (m.find(i) == m.end() && m.find(num - i) == m.end())
            {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}