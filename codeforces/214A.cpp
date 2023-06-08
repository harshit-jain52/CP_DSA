#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, count = 0;
    cin >> n >> m;
    vector<pair<int, int>> ab;

    // a^2 + b = n

    for (a = 0; a <= sqrt(n); a++)
    {
        for (b = 0; b <= n; b++)
        {
            if (a * a + b == n)
            {
                ab.push_back({a, b});
            }
        }
    }

    // a + b^2 = m

    for (a = 0; a <= m; a++)
    {
        for (b = 0; b <= sqrt(m); b++)
        {
            if (a + b * b == m)
            {
                if (find(ab.begin(), ab.end(), make_pair(a, b)) != ab.end())
                {
                    count++;
                }
            }
        }
    }

    cout << count;
}