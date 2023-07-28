#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

bool solve()
{
    int n;
    cin >> n;

    ll a[n];
    a[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }

    ll tot = n * 1LL * (n + 1) / 2, sum = a[n - 1];
    if (sum > tot)
    {
        return false;
    }

    unordered_map<ll, int> m;
    vector<ll> greaterthann;
    for (int i = 1; i < n; i++)
    {
        ll diff = a[i] - a[i - 1];
        m[diff]++;

        if (diff > n)
            greaterthann.push_back(diff);

        if (greaterthann.size() > 1)
            return false;
    }

    if (greaterthann.size() == 1)
    {
        if (sum < tot || m.size() != n - 1)
            return false;

        int num = greaterthann[0];

        for (int i = 1; i <= n; i++)
        {
            if (2 * i == num)
                continue;

            if (m.find(i) == m.end() && m.find(num - i) == m.end())
            {
                return true;
            }
        }
    }
    else
    {
        if (sum < tot)
        {
            vector<int> miss;
            for (int i = 1; i <= n; i++)
            {
                if (m.find(i) == m.end())
                {
                    miss.push_back(i);
                }
            }
            if (miss.size() != 1)
                return false;
            else if (miss[0] == tot - sum)
                return true;
        }
        else
        {
            if (m.size() != n - 2)
                return false;

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
                if (2 * i == num)
                    continue;

                if (m.find(i) == m.end() && m.find(num - i) == m.end())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}