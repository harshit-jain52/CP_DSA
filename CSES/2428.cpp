#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int i = 0, j = 0;
    ll ct = 0;

    map<int, int> m;

    while (j < n)
    {
        m[x[j]]++;

        while ((int)m.size() > k)
        {
            m[x[i]]--;
            if (m[x[i]] == 0)
                m.erase(x[i]);
            i++;
        }

        ct += (j - i + 1);
        j++;
    }

    cout << ct;
}